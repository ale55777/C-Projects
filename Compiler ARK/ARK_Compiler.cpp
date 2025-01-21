#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <string>

//https://www.geeksforgeeks.org/exception-handling-c/
//https://www.programiz.com/cpp-programming/library-function/cctype
//https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

using namespace std;

// Token types
enum TokenType {
    IDENTIFIER,
    NUMBER,
    ASSIGN,
    PLUS,
    MINUS,
    DISPLAY,
    START,
    END,
    WHILE,
    LPAREN,
    RPAREN,
    EOF_TOKEN,
    INVALID,
    FOR
};

// Token structure
struct Token {
    TokenType type;
    string value;
};



//  input string to tokens
class Lexer {
public:
    Lexer(const string& input) : input(input), index(0) {}

    // Get the next token from the input
    Token nextToken() {
        while (index < input.size() && isspace(input[index])) {
            index++;
        }

        if (index >= input.size()) {
            return { EOF_TOKEN, "" }; 
        }

        char current = input[index];

        if (isalpha(current)) {
            string identifier;
            while (index < input.size() && isalnum(input[index])) {
                identifier += input[index++];
            }
            if (identifier == "START") return { START, identifier };
            if (identifier == "END") return { END, identifier };
            if (identifier == "DISPLAY") return { DISPLAY, identifier };
            if (identifier == "WHILE") return { WHILE, identifier };

            return { IDENTIFIER, identifier };
        }

        if (isdigit(current)) {
            string number;
            while (index < input.size() && isdigit(input[index])) {
                number += input[index++];
            }
            return { NUMBER, number };
        }

        if (current == '=') {
            index++;
            return { ASSIGN, "=" };
        }

        if (current == '+') {
            index++;
            return { PLUS, "+" };
        }

        if (current == '-') {
            index++;
            return { MINUS, "-" };
        }

        if (current == '(') {
            index++;
            return { LPAREN, "(" };
        }

        if (current == ')') {
            index++;
            return { RPAREN, ")" };
        }

        return { INVALID, string(1, current) }; // Invalid 
    }

private:
    string input;
    size_t index;
};

class Parser {
public:
    Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.nextToken()) {}

    void parseAndExecute() {
        if (currentToken.type == START) {
            currentToken = lexer.nextToken(); 
            executeBlock();
        }
        else {
            throw runtime_error("Expected START token at the beginning.");
        }
    }

private:
    Lexer& lexer;
    Token currentToken;
    unordered_map<string, int> variables; 

    void consume(TokenType expectedType) {
        if (currentToken.type == expectedType) {
            currentToken = lexer.nextToken(); 
        }
        else {
            throw runtime_error("Unexpected token: " + currentToken.value);
        }
    }

  
    void executeBlock() {
        while (currentToken.type != EOF_TOKEN && currentToken.type != END) {
            if (currentToken.type == IDENTIFIER) {
                parseStatement(); 
            }
            else if (currentToken.type == DISPLAY) {
                parseDisplay(); 
            }
            else if (currentToken.type == WHILE) {
                parseWhile(); 
            }
            else {
                throw runtime_error("Unexpected token in block: " + currentToken.value);
            }
        }

        if (currentToken.type == END) {
            consume(END); 
        }
    }

    // Parse an individual statement 
    void parseStatement() {
        string varName = currentToken.value;
        consume(IDENTIFIER);

        if (currentToken.type == ASSIGN) {
            consume(ASSIGN);
            int value = parseExpression();
            variables[varName] = value;
        }
        else {
            throw runtime_error("Invalid statement for variable: " + varName);
        }
    }

 
    void parseDisplay() {
        consume(DISPLAY);

        if (currentToken.type == IDENTIFIER) {
            string varName = currentToken.value;
            consume(IDENTIFIER);
            if (variables.count(varName)) {
                cout << variables[varName] << endl;
            }
            else {
                throw runtime_error("Undefined variable: " + varName);
            }
        }
        else if (currentToken.type == NUMBER) {
            cout << currentToken.value << endl;
            consume(NUMBER);
        }
        else {
            throw runtime_error("Invalid DISPLAY statement: " + currentToken.value);
        }
    }

    void parseWhile() {
        consume(WHILE);
        consume(LPAREN);

        string varName = currentToken.value;
        consume(IDENTIFIER);
        consume(RPAREN);

        if (!variables.count(varName)) {
            throw runtime_error("Undefined variable in WHILE loop: " + varName);
        }

        int& loopVar = variables[varName];
        vector<Token> loopBody;

        while (currentToken.type != END) {
            loopBody.push_back(currentToken);
            currentToken = lexer.nextToken();
        }

        while (loopVar > 0) {
            Lexer bodyLexer(tokensToString(loopBody));
            Parser bodyParser(bodyLexer);
            bodyParser.variables = variables;
            bodyParser.executeBlock();
            variables = bodyParser.variables;
            loopVar--; 
        }
    }

    // Convert tokens back to string
    string tokensToString(const vector<Token>& tokens) {
        stringstream ss;
        for (const auto& token : tokens) {
            ss << token.value << " ";
        }
        return ss.str();
    }

    int parseExpression() {
        int value = parseTerm();

        while (currentToken.type == PLUS || currentToken.type == MINUS) {
            TokenType op = currentToken.type;
            consume(op);

            int nextValue = parseTerm();

            if (op == PLUS) {
                value += nextValue;
            }
            else if (op == MINUS) {
                value -= nextValue;
            }
        }

        return value;
    }

    // Parsing (a number or a variable)
    int parseTerm() {
        if (currentToken.type == NUMBER) {
            try {
                int value = stoi(currentToken.value);
                consume(NUMBER);
                return value;
            }
            catch (const invalid_argument&) {
                throw runtime_error("Invalid number: " + currentToken.value);
            }
        }
        else if (currentToken.type == IDENTIFIER) {
            string varName = currentToken.value;
            consume(IDENTIFIER);
            if (variables.count(varName)) {
                return variables[varName];
            }
            else {
                throw runtime_error("Undefined variable: " + varName);
            }
        }
        else {
            throw runtime_error("Invalid term in expression: " + currentToken.value);
        }
    }
};

// Main function
int main() {
    ifstream inputFile("arkloop.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string arkCode = buffer.str();

    Lexer lexer(arkCode);
    Parser parser(lexer);

    try {
        parser.parseAndExecute();
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
