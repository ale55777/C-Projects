
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 1000;
const int MAX_USERS = 100;

class User {
public:
    string username;
    string password;

    User() {}

    User(string uname, string pwd) : username(uname), password(pwd) {}

    bool registerUser(User users[], int& userCount) {
        for (int i = 0; i < userCount; i++) {

            if (users[i].username == username) {
            
                cout << "Username already exists. Please choose a different username." << endl;
                
                return false;
            }
        }
        if (userCount < MAX_USERS) {
            
            users[userCount++] = *this;
            
            cout << "User registered successfully." << endl;
            return true;
        }
        else {
            
            cout << "User limit reached. Cannot register more users." << endl;
            
            return false;
        }
    }

    bool loginUser(const User users[], int userCount) {
       
        for (int i = 0; i < userCount; i++) {
        
            if (users[i].username == username && users[i].password == password) {
                cout << "Login successful. Welcome, " << username << "!" << endl;
                return true;
            }
        }
        cout << "Invalid username or password. Please try again." << endl;
        return false;
    }
};

class ToDoList {
private:
    string tasks[MAX_SIZE];
    int top;
    string filename;

public:
   
    ToDoList() : top(-1) {}

    void setFilename(const string& user) {
    
        filename = user + "_tasks.txt";
    }

    void addTask(const string& task) {
        
        if (top == MAX_SIZE - 1) {
        
            cout << "ToDo List is full. Cannot add more tasks." << endl;
            return;
        }
        
        tasks[++top] = task;
        
        cout << "Task \"" << task << "\" added to the ToDo List." << endl;
    }

    void completeTask() {
       
        if (top == -1) {
            
            cout << "ToDo List is empty. No task to complete." << endl;
        
            return;
        }
        cout << "Task \"" << tasks[top--] << "\" completed and removed from the ToDo List." << endl;
    }

    void displayTasks() {
        
        if (top == -1) {
        
            cout << "ToDo List is empty." << endl;
            return;
        }
        cout << "Tasks in the ToDo List:" << endl;
       
        for (int i = top; i >= 0; i--) {
        
            cout << "- " << tasks[i] << endl;
        }
    }

    void saveToFile() {
        
        ofstream outFile(filename);
        
        if (!outFile) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }
        
        for (int i = 0; i <= top; ++i) {
        
            outFile << tasks[i] << endl;
        }
        
        outFile.close();
        
        cout << "Tasks saved to file \"" << filename << "\" successfully." << endl;
    }

    void loadFromFile() {
        
        ifstream inFile(filename);
        
        if (!inFile) {
        
            cerr << "Error: Unable to open file for reading." << endl;
            
            return;
        }
        string task;
        
        top = -1; // Reset the task list
        while (getline(inFile, task)) {
        
            addTask(task);
        }
        
        inFile.close();
        
        cout << "Tasks loaded from file \"" << filename << "\" successfully." << endl;
    }

    void printMenu() {
        cout << "\n";
        cout << "+---------------------------+\n";
        cout << "|         Menu:             |\n";
        cout << "+---------------------------+\n";
        cout << "| 1. Add Task               |\n";
        cout << "| 2. Complete Task          |\n";
        cout << "| 3. Display Tasks          |\n";
        cout << "| 4. Save Tasks to File     |\n";
        cout << "| 5. Load Tasks from File   |\n";
        cout << "| 6. Exit                   |\n";
        cout << "+---------------------------+\n";
    }
};

void saveUsersToFile(const User users[], int userCount, const string& filename) {
    
    ofstream outFile(filename);
    
    if (!outFile) {
    
        cout << "Error: Unable to open file for writing." << endl;
        
        return;
    }
    for (int i = 0; i < userCount; ++i) {
        
        outFile << users[i].username << ' ' << users[i].password << endl;
    }
    outFile.close();
    
    cout << "Users saved to file \"" << filename << "\" successfully." << endl;
}

/*void loadUsersFromFile(User users[], int& userCount, const string& filename) {
    
    ifstream inFile(filename);
    
    if (!inFile) {
    
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }
    userCount = 0;
    string username, password;
   
    while (inFile >> username >> password) {
    
        if (userCount < MAX_USERS) {
        
            users[userCount++] = User(username, password);
        }
        else {
           
            cout << "User limit reached while loading users from file." << endl;
            
            break;
        }
    }
    inFile.close();

    cout << "Users loaded from file \"" << filename << "\" successfully." << endl;
}*/

int main() {

    User users[MAX_USERS];

    int userCount = 0;

    ToDoList myList;

    int choice;

    string task, username, password;

    User currentUser;

    //loadUsersFromFile(users, userCount, "users.txt");



    while (true) {

        cout << "1. Register\n2. Login\n3. Exit\n";

        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 3) {
            break;
        }

        switch (choice) {
        case 1:

            cout << "Enter username: ";

            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            currentUser = User(username, password);

            currentUser.registerUser(users, userCount);


            saveUsersToFile(users, userCount, "users.txt");
            break;

        case 2:

            cout << "Enter username: ";

            cin >> username;

            cout << "Enter password: ";

            cin >> password;

            currentUser = User(username, password);

            if (currentUser.loginUser(users, userCount)) {

                myList.setFilename(username);

                int userChoice;

                do {

                    myList.printMenu();

                    cout << "Enter your choice: ";

                    cin >> userChoice;

                    switch (userChoice) {

                    case 1:

                        cout << "TASK TO-DO >> : ";

                        cin.ignore();

                        getline(cin, task);

                        myList.addTask(task);

                        break;

                    case 2:

                        myList.completeTask();
 
                        break;

                    case 3:
                        
                        myList.displayTasks();
                       
                        break;

                    case 4:

                        myList.saveToFile();

                        break;

                    case 5:
                        myList.loadFromFile();

                        break;

                    case 6:

                        cout << "====== Exiting program ======" << endl;

                        break;
                    default:

                        cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                    }
                } while (userChoice != 6);
            }
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}
