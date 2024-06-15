#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <climits>
#include <limits.h>
#include <queue>
#include <set>
#include <ctime>
#include <utility>

using namespace std;




const int MAP_SIZE = 10;


enum NodeType {
    CLEAR_PATH, OBSTACLE, JEWEL, POTION, WEAPON,
    DEATH_POINT, DRAGON, GOBLIN, WEREWOLF, CRYSTAL
};


struct NodeMat {
    int row;
    int col;
    char symbol;

    NodeMat() {}

    NodeMat(int r, int c, char s) {
        row = r;
        col = c;
        symbol = s;
    }
};


bool isValid(int row, int col) {
    return (row >= 0 && row < MAP_SIZE&& col >= 0 && col < MAP_SIZE);
}

void convertToAdjacencyMatrix(const char map[][MAP_SIZE], int adjacencyMatrix[][MAP_SIZE]) {
    cout << "GRAPH IS: " << endl << endl;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // ind the connections between 'C' nodes
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // If the current position is a 'C' node
            if (map[i][j] == 'C') {
                // Check  positions for 'C' nodes
                
                if (isValid(i - 1, j) && map[i - 1][j] == 'C') {
                    adjacencyMatrix[i][j] = 1;
                    cout << "(" << i << "," << j << ") - (" << i - 1 << "," << j << ")" << endl;

                }
                if (isValid(i + 1, j) && map[i + 1][j] == 'C') {
                    adjacencyMatrix[i][j] = 1; 
                    cout << "(" << i << "," << j << ") - (" << i + 1 << "," << j << ")" << endl;

                }
                if (isValid(i, j - 1) && map[i][j - 1] == 'C') {
                    adjacencyMatrix[i][j] = 1; 
                    cout << "(" << i << "," << j << ") - (" << i << "," << j - 1 << ")" << endl;

                }
                if (isValid(i, j + 1) && map[i][j + 1] == 'C') {
                    adjacencyMatrix[i][j] = 1; 
                    cout << "(" << i << "," << j << ") - (" << i << "," << j + 1 << ")" << endl;

                }
            }
        }
    }
}


void adjMat()
{
    char map[MAP_SIZE][MAP_SIZE] = {
        {'C', 'C', 'C', 'x', 'x', 'Z', 'C', '&', 'P', '#'},
        {'C', 'x', 'W', 'x', 'C', 'P', 'J', 'J', '@', 'C'},
        {'*', 'C', '#', '$', 'x', 'W', 'C', '#', '#', 'C'},
        {'C', 'C', 'C', '@', '#', 'C', '#', 'C', 'W', '#'},
        {'C', '#', '#', 'C', '#', 'C', 'J', '%', 'C', 'W'},
        {'C', 'C', 'C', 'P', '#', 'C', 'C', '#', '%', '#'},
        {'$', '%', 'C', 'C', '#', '$', '%', 'C', '%', '#'},
        {'x', 'P', 'C', '#', 'W', 'J', '#', '#', '%', 'C'},
        {'#', 'J', 'J', 'C', '%', 'C', 'P', 'P', '#', '#'},
        {'%', 'C', 'C', '%', 'C', 'C', '@', 'C', 'P', 'C'}
    };

    int adjacencyMatrix[MAP_SIZE][MAP_SIZE];
    convertToAdjacencyMatrix(map, adjacencyMatrix);

    cout << "\n\nADJACENCY MATRIX\n\n";
    // Print the adjacency matrix
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


class Node {
public:
    int id;
    int reward_score;
    NodeType type;
    int count;
    Node* left;
    Node* right;
    int height;

    Node(int id, int reward_score, NodeType type) {
        this->id = id;
        this->reward_score = reward_score;
        this->type = type;
        this->count = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    int height(Node* N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int balanceFactor(Node* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int id, int reward_score, NodeType type) {
        if (node == nullptr)
            return new Node(id, reward_score, type);

        if (id < node->id) {
            node->left = insert(node->left, id, reward_score, type);
        }
        else if (id > node->id) {
            node->right = insert(node->right, id, reward_score, type);
        }
        else {
            node->count++;
            return node;
        }

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && id < node->left->id)
            return rightRotate(node);

        if (balance < -1 && id > node->right->id)
            return leftRotate(node);

        if (balance > 1 && id > node->left->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && id < node->right->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
    Node* deleteNode(Node* root, int id) {
        if (root == nullptr)
            return root;

        if (id < root->id)
            root->left = deleteNode(root->left, id);
        else if (id > root->id)
            root->right = deleteNode(root->right, id);
        else {
            if (root->count > 1) {
                root->count--;
            }
            else {
                if ((root->left == nullptr) || (root->right == nullptr)) {
                    Node* temp = root->left ? root->left : root->right;

                    if (temp == nullptr) {
                        temp = root;
                        root = nullptr;
                    }
                    else {
                        *root = *temp;
                    }
                    delete temp;
                }
                else {
                    Node* temp = minValueNode(root->right);
                    root->id = temp->id;
                    root->reward_score = temp->reward_score;
                    root->count = temp->count;
                    root->right = deleteNode(root->right, temp->id);
                }
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + std::max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* removeReward(Node* node, NodeType enemyType) {
        if (!node) return node;

        NodeType rewardType;
        if (enemyType == DRAGON) rewardType = JEWEL;
        else if (enemyType == GOBLIN) rewardType = POTION;
        else if (enemyType == WEREWOLF) rewardType = WEAPON;
        else return node;

        if (node->type == rewardType && node->count > 0) {
            node->count--;
            if (node->count == 0) {
                return deleteNode(node, node->id);
            }
            return node;
        }

        node->left = removeReward(node->left, enemyType);
        node->right = removeReward(node->right, enemyType);
        return node;
    }

    int calculateScore(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int score = 0;
        if (node->type == JEWEL) score += 50 * node->count;
        else if (node->type == WEAPON) score += 30 * node->count;
        else if (node->type == POTION) score += 70 * node->count;
        return score + calculateScore(node->left) + calculateScore(node->right);
    }

    void printTree(Node* node) {
        if (node == nullptr)
            return;

        // Print node
        std::cout << "ID: " << node->id << ", Reward Score: " << node->reward_score << ", Type: " << node->type << ", Count: " << node->count << std::endl;

        //print left and right trees
        printTree(node->left);
        printTree(node->right);
    }

    void printCompleteTree() {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
        }
        else {
            std::cout << "Complete Tree:" << std::endl;
            printTree(root);
        }
    }


};




class Nodes {
public:
    int x;
    int y;
    char type;
    bool visited;
    Nodes* parent;
    int score;
    int reward_id;

    Nodes() {
        x = 0;
        y = 0;
        type = '\0';
        visited = false;
        parent = nullptr;
        score = INT_MAX;
        reward_id = -1; 
    }

    Nodes(int x, int y, char type) {
        this->x = x;
        this->y = y;
        this->type = type;
        this->visited = false;
        parent = nullptr;
        score = INT_MAX;
        reward_id = -1;
    }
};

void updateInventory(AVLTree& inventory, Nodes* node, NodeType type) {

    if (node->reward_id != -1) {
        inventory.root = inventory.deleteNode(inventory.root, node->reward_id);
    }

    if (node->type == 'J') {
        node->reward_id = rand() % 200;
        inventory.root = inventory.insert(inventory.root, node->reward_id, 50, type);
    }
    else if (node->type == 'W') {
        node->reward_id = rand() % 200;
        inventory.root = inventory.insert(inventory.root, node->reward_id, 30, type);
    }
    else if (node->type == 'P') {
        node->reward_id = rand() % 200;
        inventory.root = inventory.insert(inventory.root, node->reward_id, 70, type);
    }
}


void resetMap(Nodes gameMap[MAP_SIZE][MAP_SIZE], AVLTree& inventory, NodeType type) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            gameMap[i][j].visited = false;
            gameMap[i][j].parent = nullptr;
            gameMap[i][j].score = INT_MAX;
            if (gameMap[i][j].reward_id != -1) {
                // int* reward_id_ptr = &gameMap[i][j].reward_id;
                updateInventory(inventory, &gameMap[i][j], type);
            }
        }
    }
}

Nodes* findNodeWithMinScore(Nodes gameMap[MAP_SIZE][MAP_SIZE]) {
    int minScore = INT_MAX;
    Nodes* minNode = nullptr;

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (!gameMap[i][j].visited && gameMap[i][j].score < minScore) {
                minScore = gameMap[i][j].score;
                minNode = &gameMap[i][j];
            }
        }
    }

    return minNode;
}

void printPath(Nodes* node) {
    stack<Nodes*> s;
    while (node != nullptr) {
        s.push(node);
        node = node->parent;
    }

    while (!s.empty()) {
        Nodes* n = s.top();
        s.pop();
        cout << "(" << n->x << ", " << n->y << ")";
        if (!s.empty()) {
            cout << " -> ";
        }
    }
}

int getWeight(char type) {
    switch (type) {
    case 'C':
    case 'J':
    case 'P':
    case 'W':
    case '*':
        return 0;
    case '%':
        return INT_MAX;
    case '#':
        return INT_MAX / 2;
    default:
        return 1;
    }
}



//dijkstra

void findShortestPath(Nodes gameMap[MAP_SIZE][MAP_SIZE], int startX, int startY, int endX, int endY, AVLTree& inventory, NodeType type) {
    resetMap(gameMap, inventory, type);
    gameMap[startX][startY].score = 0;

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    Nodes* goalNode = nullptr;

    AVLTree rewardInventory;
    int nextRewardId = 100;

    while (true) {
        Nodes* currentNode = findNodeWithMinScore(gameMap);

        if (currentNode == nullptr) {
            break;
        }

        currentNode->visited = true;

      

        if (currentNode->x == endX && currentNode->y == endY) {
            goalNode = currentNode;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + dx[i];
            int newY = currentNode->y + dy[i];

            if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE) {
                Nodes* neighbor = &gameMap[newX][newY];
                if (!neighbor->visited && neighbor->type != '#') {
                    int newScore = currentNode->score + 1;
                    if (newScore < neighbor->score) {
                        neighbor->score = newScore;
                        neighbor->parent = currentNode;
                    }
                }
            }
        }
    }

    if (goalNode != nullptr) {
        std::stack<Nodes*> path;
        Nodes* currentNode = goalNode;
        while (currentNode->parent != nullptr) {
            path.push(currentNode);
            currentNode = currentNode->parent;
        }
        std::cout << "Moves to reach the crystal:" << std::endl;
        while (!path.empty()) {
            Nodes* node = path.top();
            std::cout << "(" << node->x << ", " << node->y << ")" << std::endl;
            path.pop();
        }
    }
    else {
        std::cout << "No path found." << std::endl;
    }


}



class NodeMST {
public:
    int x;
    int y;
    char type;
    bool visited;
    NodeMST* parent;
    int score;

    NodeMST()
    {
        x = 0;
        y = 0;
        type = '\0';
        visited = false;
        parent = nullptr;
        score = 0; 
    }

    NodeMST(int x, int y, char type) {
        this->x = x;
        this->y = y;
        this->type = type;
        this->visited = false;
        parent = nullptr;
        score = 0;
    }
};



//start of kruskal
// kruskal algorithm
class Edge {
public:
    NodeMST* start;
    NodeMST* end;
    int weight;

    Edge(NodeMST* start, NodeMST* end, int weight) {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

bool compareEdges(Edge* e1, Edge* e2) {
    return e1->weight < e2->weight;
}

NodeMST* findParent(NodeMST* node) {
    while (node->parent != nullptr) {
        node = node->parent;
    }
    return node;
}

// Union two nodes 
void unionNodes(NodeMST* node1, NodeMST* node2) {
    NodeMST* parent1 = findParent(node1);
    NodeMST* parent2 = findParent(node2);
    parent1->parent = parent2;
}

int playerScore = 0;
void kruskal(NodeMST gameMap[MAP_SIZE][MAP_SIZE]) {
    
    Edge* edges[100];
    int numEdges = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            NodeMST* node = &gameMap[i][j];
            if (node->type == 'C' || node->type == '*' || node->type == 'J' || node->type == 'W' || node->type == 'P') {
                
                if (j < MAP_SIZE - 1) {
                    NodeMST* neighbor = &gameMap[i][j + 1];
                    if (neighbor->type == 'C' || neighbor->type == '*' || neighbor->type == 'J' || neighbor->type == 'W' || neighbor->type == 'P') {
                        int weight = (node->type == '*' || neighbor->type == '*') ? 0 : 1;
                        Edge* edge = new Edge(node, neighbor, weight);
                        edges[numEdges] = edge;
                        numEdges++;
                    }
                }
               
                if (i < MAP_SIZE - 1) {
                    NodeMST* neighbor = &gameMap[i + 1][j];
                    if (neighbor->type == 'C' || neighbor->type == '*' || neighbor->type == 'J' || neighbor->type == 'W' || neighbor->type == 'P') {
                        int weight = (node->type == '*' || neighbor->type == '*') ? 0 : 1;
                        Edge* edge = new Edge(node, neighbor, weight);
                        edges[numEdges] = edge;
                        numEdges++;
                    }
                }
            }
        }
    }
    
    sort(edges, edges + numEdges, compareEdges);
    // Creatinf a union-find
    for (int i = 0; i < numEdges; i++) {
        Edge* edge = edges[i];
        NodeMST* start = edge->start;
        NodeMST* end = edge->end;
        if (findParent(start) != findParent(end)) {
            unionNodes(start, end);
            cout << "(" << start->x << ", " << start->y << ") -- (" << end->x << ", " << end->y << ")" << endl;
            // Collect reward 
            if (end->visited && (end->type == 'J' || end->type == 'W' || end->type == 'P')) {
                if (end->type == 'J') {
                    playerScore += 50;
                    cout << "Collected a jewel! +50 points" << endl;
                }
                else if (end->type == 'W') {
                    playerScore += 30;
                    cout << "Collected a weapon! +30 points" << endl;
                }
                else if (end->type == 'P') {
                    playerScore += 70;
                    cout << "Collected a potion! +70 points" << endl;
                }
            }
            end->visited = true;
        }
    }
}

//ending kruskal 
 //start prim 


//Prims Algo
const int ROWS = 10;
const int COLS = 10;
const int INF = INT_MAX;

char matrix[ROWS][COLS] = { 
    {'C', 'C', 'C', 'x', 'x', 'Z', 'C', '&', 'P', '#'},
    {'C', 'C', '%', 'C', 'C', 'C', 'C', '%', 'C', 'C'},
    {'C', 'C', 'C', 'C', 'C', '%', 'C', '%', 'C', 'C'},
    {'C', 'C', 'C', 'C', '%', 'C', 'C', 'C', 'C', 'C'},
    {'C', '#', '#', 'C', '#', 'C', 'J', '%', 'C', 'W' },
    {'C', 'C', 'C', 'P', '#', 'C', 'C', '#', '%', '#'},
    {'C', 'C', '%', 'C', 'C', 'C', 'C', 'C', 'C', 'C'},
    {'C', 'C', 'C', '%', 'C', 'C', 'C', 'C', 'C', 'C'},
    {'%', 'C', 'C', '%', 'C', 'C', '@', '*', 'P', 'C' },
    {'C', 'C', 'C', '@', '#', 'C', '#', 'C', 'W', '#'}
};


int weights[ROWS][COLS]; 
bool visited[ROWS][COLS]; 

int get_weight(int row, int col) {
    if (matrix[row][col] == '%') {
        return INF; 
    }
    else if (matrix[row][col] == '@') {
        return INF; 
    }
    else if (matrix[row][col] == '&') {
        return INF; 
    }
    else if (matrix[row][col] == '#') {
        return INF; 
    }
    else if (matrix[row][col] == 'J') {
        return 30; 
    }
    else if (matrix[row][col] == 'W') {
        return 50; 
    }
    else if (matrix[row][col] == 'P') {
        return 70; 
    }
    else {
        return 1; 
    }
}

void init_weights() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            weights[row][col] = get_weight(row, col);
        }
    }
}

int min_weight_node() {
    int min_weight = INF;
    int min_row, min_col;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (!visited[row][col] && weights[row][col] < min_weight) {
                min_weight = weights[row][col];
                min_row = row;
                min_col = col;
            }
        }
    }
    return min_row * COLS + min_col; // convert 2D into 1d
}

void prims_algorithm() {
    init_weights(); 
    int total_score = 0;
    int parent[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            parent[row][col] = -1; // initializzing parent 
        }
    }
    for (int i = 0; i < ROWS * COLS; i++) {
        int node = min_weight_node(); 
        visited[node / COLS][node % COLS] = true; 
        total_score += weights[node / COLS][node % COLS]; 
        if (matrix[node / COLS][node % COLS] == '*') { 
            cout << "The minimum weight to reach the end node is " << total_score << endl;
            //printing edges 
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (parent[row][col] != -1) {
                        int parent_row = parent[row][col] / COLS;
                        int parent_col = parent[row][col] % COLS;
                        cout << "(" << row << "," << col << ") -- (" << parent_row << "," << parent_col << ")" << endl;
                    }
                }
            }
            return;
        }
        //update wieghts and parnt adj nodes
        if (node % COLS != 0 && !visited[node / COLS][node % COLS - 1]) { // left node
            if (weights[node / COLS][node % COLS - 1] > weights[node / COLS][node % COLS]) {
                weights[node / COLS][node % COLS - 1] = weights[node / COLS][node % COLS];
                parent[node / COLS][node % COLS - 1] = node;
            }
        }
        if (node % COLS != COLS - 1 && !visited[node / COLS][node % COLS + 1]) { // right node
            if (weights[node / COLS][node % COLS + 1] > weights[node / COLS][node % COLS]) {
                weights[node / COLS][node % COLS + 1] = weights[node / COLS][node % COLS];
                parent[node / COLS][node % COLS + 1] = node;
            }
        }
        if (node / COLS != 0 && !visited[node / COLS - 1][node % COLS]) { // top node
            if (weights[node / COLS - 1][node % COLS] > weights[node / COLS][node % COLS]) {
                weights[node / COLS - 1][node % COLS] = weights[node / COLS][node % COLS];
                parent[node / COLS - 1][node % COLS] = node;
            }
        }
        if (node / COLS != ROWS - 1 && !visited[node / COLS + 1][node % COLS]) { // bottom node
            if (weights[node / COLS + 1][node % COLS] > weights[node / COLS][node % COLS]) {
                weights[node / COLS + 1][node % COLS] = weights[node / COLS][node % COLS];
                parent[node / COLS + 1][node % COLS] = node;
            }
        }
    }
}
//

//
//
//
//


//


struct Nodee {
    int row;
    int col;
    char symbol;

    Nodee() {}

    Nodee(int r, int c, char s) {
        row = r;
        col = c;
        symbol = s;
    }
};

bool isValidPosition(int row, int col) {
    return (row >= 0 && row < MAP_SIZE&& col >= 0 && col < MAP_SIZE);
}




void avl()
{
    char map[MAP_SIZE][MAP_SIZE] = {
        {'C', 'C', 'C', '&', 'C', 'Z', 'C', '&', 'P', '#'},
        {'C', 'J', 'W', '&', 'c', 'P', 'J', 'J', '@', 'C'},
        {'C', 'C', '#', '$', 'x', 'W', 'C', '#', '#', 'C'},
        {'C', 'C', 'C', '@', '#', 'C', '#', 'C', 'W', '#'},
        {'C', '#', '#', 'C', '#', 'C', 'J', '%', 'C', 'W'},
        {'C', 'C', 'C', 'P', '#', '*', 'C', '#', '%', '#'},
        {'$', '%', 'C', 'C', '#', '$', '%', 'C', '%', '#'},
        {'x', 'P', 'C', '#', 'W', 'J', '#', '#', '%', 'C'},
        {'#', 'J', 'J', 'C', '%', 'C', 'P', 'P', '#', '#'},
        {'%', 'C', 'C', '%', 'C', 'C', '@', 'C', 'P', 'C'}
    };

    Nodes gameMap[MAP_SIZE][MAP_SIZE];

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            gameMap[i][j] = Nodes(i, j, map[i][j]);
        }
    }

    srand(static_cast<unsigned int>(time(0)));

    AVLTree inventory;
    int id, count;
    bool crystal = false;
    inventory.root = inventory.insert(inventory.root, 100, 0, CLEAR_PATH);
    bool foundCrystal = false;
    while (!foundCrystal) {
        int id = rand() % 201;
        NodeType type = static_cast<NodeType>(rand() % 10);

        if (type != DEATH_POINT) {
            inventory.root = inventory.insert(inventory.root, id, 0, type);
            if (type == CRYSTAL) foundCrystal = true;
            else if (type == DRAGON || type == GOBLIN || type == WEREWOLF) {
                inventory.root = inventory.removeReward(inventory.root, type);
            }

        }

    }
    cout << "Shortest path from (0, 0) to the crystal:" << endl;
    findShortestPath(gameMap, 0, 0, 5, 5, inventory, CRYSTAL);

    cout << "Shortest path from custom location (2, 4) to the crystal:" << endl;
    findShortestPath(gameMap, 2, 4, 5, 5, inventory, CRYSTAL);

    int finalScore = inventory.calculateScore(inventory.root);
    std::cout << "Final score: " << finalScore << std::endl;

    inventory.printCompleteTree();

}




//ending dikjstra


//start floyd

const int MAX_SIZE_FLOYD = 100;

enum ItemType {
    JEWEL_F = 0,
    WEAPON_F = 1,
    POTION_F = 2,
    ITEM_COUNT = 3
};

struct Player {
    int row;
    int col;
    int score;
    int inventory[ITEM_COUNT];
};

void populateMap(char map[][MAX_SIZE_FLOYD], int rows, int cols) {
    srand(time(0));
    const char SYMBOLS[] = { 'C', 'J', 'P', 'W', '%', '#', '&', '$', '@', '*' };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int random_index = rand() % 10;
            map[i][j] = SYMBOLS[random_index];
        }
    }
}

void printMap(char map[][MAX_SIZE_FLOYD], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int calculateCost(char symbol) {
    switch (symbol) {
    case 'C': return 1;
    case 'J': return 1;
    case 'P': return 1;
    case 'W': return 1;
    case '%': return INF;
    case '#': return 100;
    case '&': return 1;
    case '$': return 1;
    case '@': return 1;
    case '*': return 1;
    default: return INF;
    }
}

void initializeGraph(int graph[][MAX_SIZE_FLOYD], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = INF;
            }
        }
    }
}


void createGraph(char map[][MAX_SIZE_FLOYD], int graph[][MAX_SIZE_FLOYD], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            for (int k = 0; k < 4; k++) {
                int newRow = i + (k == 0 ? -1 : (k == 1 ? 1 : 0));
                int newCol = j + (k == 2 ? -1 : (k == 3 ? 1 : 0));
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newIndex = newRow * cols + newCol;
                    char symbol = map[newRow][newCol];
                    if (symbol == '#' || symbol == '&' || symbol == '$' || symbol == '@' || symbol == '%') {
                        graph[index][newIndex] = INF;
                    }
                    else {
                        graph[index][newIndex] = 1;
                    }
                }
            }
        }
    }
}

void floydWarshall(int graph[][MAX_SIZE_FLOYD], int dist[][MAX_SIZE_FLOYD], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void updatePlayer(Player& player, char symbol) {
    switch (symbol) {
    case 'J':
        player.inventory[JEWEL_F]++;
        player.score += 50;
        break;
    case 'P':
        player.inventory[POTION_F]++;
        player.score += 70;
        break;
    case 'W':
        player.inventory[WEAPON_F]++;
        player.score += 30;
        break;
    case '&':
        player.inventory[JEWEL_F]--;
        player.score -= 50;
        break;
    case '$':
        player.inventory[POTION_F]--;
        player.score -= 70;
        break;
    case '@':
        player.inventory[WEAPON_F]--;
        player.score -= 30;
        break;
    }
}

struct Position {
    int row;
    int col;
};

Position findCrystal(char map[][MAX_SIZE_FLOYD], int rows, int cols) {
    Position crystal;
    crystal.row = -1;
    crystal.col = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == '*') {
                crystal.row = i;
                crystal.col = j;
                return crystal;
            }
        }
    }
    return crystal;
}

void moveToCrystal(Player& player, char map[][MAX_SIZE_FLOYD], int dist[][MAX_SIZE_FLOYD], int rows, int cols) {
    Position crystal = findCrystal(map, rows, cols);
    int crystalIndex = crystal.row * cols + crystal.col;
    int playerIndex = player.row * cols + player.col;
    int minDist = dist[playerIndex][crystalIndex];
    std::cout << "Shortest path from (" << player.row << ", " << player.col << ") to the crystal: " << minDist << std::endl;

    while (playerIndex != crystalIndex) {
        int minDistNext = minDist;
        int newRow = -1;
        int newCol = -1;

        for (int i = 0; i < 4; i++) {
            int tempRow = player.row + (i == 0 ? -1 : (i == 1 ? 1 : 0));
            int tempCol = player.col + (i == 2 ? -1 : (i == 3 ? 1 : 0));
            if (tempRow >= 0 && tempRow < rows && tempCol >= 0 && tempCol < cols) {
                int newIndex = tempRow * cols + tempCol;
                if (dist[newIndex][crystalIndex] < minDistNext) {
                    minDistNext = dist[newIndex][crystalIndex];
                    newRow = tempRow;
                    newCol = tempCol;
                }
            }
        }

        if (newRow == -1 && newCol == -1) {
            std::cout << "No path found to the crystal" << std::endl;
            break;
        }

        player.row = newRow;
        player.col = newCol;
        playerIndex = player.row * cols + player.col;
        minDist = minDistNext;

        updatePlayer(player, map[player.row][player.col]);
        std::cout << "Player moved to (" << player.row << ", " << player.col << "). Score: " << player.score << std::endl;
    }
}



void floyd()
{
    int rows = 10;
    int cols = 10;

    char map[MAX_SIZE_FLOYD][MAX_SIZE_FLOYD];
    int graph[MAX_SIZE_FLOYD][MAX_SIZE_FLOYD] = { 0 };
    int dist[MAX_SIZE_FLOYD][MAX_SIZE_FLOYD] = { 0 };

    populateMap(map, rows, cols);
    printMap(map, rows, cols);

    initializeGraph(graph, rows * cols);
    createGraph(map, graph, rows, cols);
    floydWarshall(graph, dist, rows * cols);

    Player player = { 0, 0, 0, {0, 0, 0} };
    updatePlayer(player, map[player.row][player.col]);
    std::cout << "Starting location: (" << player.row << ", " << player.col << "). Score: " << player.score << std::endl;

    moveToCrystal(player, map, dist, rows, cols);
    std::cout << "Final score: " << player.score << std::endl;

}









int main()
{

    cout << "----------------------------------------------------------------" << endl;

    cout << "\n\n";
    cout << "Anas Mohsin" << endl;
    cout << "Ahsan Bilal" << endl;
    cout << "Ali Raza Khan" << endl;
    cout << "\t---------------------------------------------------------\n";
    cout << "\t|*******************************************************|\n";
    cout << "\t---------------------------------------------------------\n";
    cout << "\t|\t\t\t\t\t\t\t|\n";
    cout << "\t|  	 `The Quest for the Crystal Kingdom'	\t|\n";
    cout << "\t|\t\t\t\t\t\t\t|\n";
    cout << "\t_____________\t\t\t\t_______________\n";
    cout << "\t|\t_____\t\t\t\t_____\t\t|\n";
    cout << "\t|\t| | | |\t\t\t\t| | | |\t\t|\n";
    cout << "\t|\t```````\t\t\t\t```````\t\t|\n";
    cout << "\t|\t\t\t\t\t\t\t|\n";
    cout << "\t|\t\t\t\t\t\t\t|\n";
    cout << "\t|\t\t\t__________\t\t\t|\n";
    cout << "\t|\t\t\t|        |\t\t\t|\n";
    cout << "\t|\t\t\t|        |\t\t\t|\n";
    cout << "\t_____________\t\t|        |\t_______________\n";
    cout << "\t|\t_____\t\t|        |\t_____\t\t|\n";
    cout << "\t|\t| | | |\t\t|        |\t| | | |\t\t|\n";
    cout << "\t|\t```````\t\t|        |\t```````\t\t|\n";
    cout << "\t|\t\t\t|        |\t\t\t|\n";
    cout << "\t|\t\t\t|        |\t\t\t|\n";
    cout << "\t|_______________________________________________________|\n";


    cout << endl;

    char map[MAP_SIZE][MAP_SIZE] = {
        {'C', 'C', 'C', 'x', '*', 'Z', 'C', '&', 'P', '#'},
        {'C', 'x', 'W', 'x', 'c', 'P', 'J', 'J', '@', 'C'},
        {'C', 'C', '#', '$', 'x', 'W', 'C', '#', '#', 'C'},
        {'C', 'C', 'C', '@', '#', 'C', '#', 'C', 'W', '#'},
        {'C', '#', '#', 'C', '#', 'C', 'J', '%', 'C', 'W'},
        {'C', 'C', 'C', 'P', '#', 'C', 'C', '#', '%', '#'},
        {'$', '%', 'C', 'C', '#', '$', '%', 'C', '%', '#'},
        {'x', 'P', 'C', '#', 'W', 'J', '#', '#', '%', 'C'},
        {'#', 'J', 'J', 'C', '%', 'C', 'P', 'P', '#', '#'},
        {'%', 'C', 'C', '%', 'C', 'C', '@', 'C', 'P', 'C'}
    };


    NodeMST gameMap[MAP_SIZE][MAP_SIZE];


    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            gameMap[i][j] = NodeMST(i, j, map[i][j]);
        }
    }





    int choice;
    

    do {
        cout << "\n\n\n\n\nPlease choose an algorithm to use: " << endl;

        cout << "1. Kruskal's algorithm" << endl;
        cout << "2. Prim's algorithm" << endl;
        cout << "3. Dijkstra with AVL" << endl;
        cout << "4. Adjacency matrix with graph" << endl;
        cout << "5. Floyd Warshal Algorithm" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;
        switch (choice) {
        case 1:
            kruskal(gameMap);
            break;
        case 2:
            prims_algorithm();
            break;
        case 3:
            avl();
            break;
        case 4:
            adjMat();
            break;
        case 5:
            floyd();
            break;
        default:
            cout << "Invalid choice. Please choose 1 2 3 4 5 6." << endl;
            break;
        }
    } while (choice != 0);
   



    return 0;
}




