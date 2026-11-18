#include <iostream>
#include <queue>
using namespace std;

class Node {
public:    
    Node* left;
    Node* right;
    int value;

    Node (int value) {
        this->left = NULL;
        this->right = NULL;
        this->value = value;
    }
};

Node* input() {
    int value;
    cin >> value;
    if (value == -1) return NULL;

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftNode, rightNode;
        cin >> leftNode >> rightNode;
        if (leftNode != -1) {
            current->left = new Node(leftNode);
            q.push(current->left);
        }
        if (rightNode != -1) {
            current->right = new Node(rightNode);
            q.push(current->right);
        }
    }

    return root;
}

void printLevelNodes(Node* root, int X) {
    if (!root) {
        cout << "Invalid";
        return;
    }

    queue<Node*> q;
    q.push(root);

    int currentLevel = 0;

    while (!q.empty() && currentLevel <= X) {
        int levelSize = q.size(); // Store the size, q.size() = Number of nodes at current level

        if (currentLevel == X) {
            // Node* temp = q.front();
            // q.pop();
            // cout << temp->value << " ";

            // for (int i = 0; i < q.size(); i++) { 
             for (int i = 0; i < levelSize; i++) { 
                Node* temp = q.front();
                q.pop();
                cout << temp->value << " ";
            }
            return;
        } 
        
        // for (int i = 0; i < q.size(); i++) {
        for (int i = 0; i < levelSize; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        currentLevel++;
    }
    cout << "Invalid";
}
 
int main() {
    Node* root = input();
    int X;
    cin >> X;
    printLevelNodes(root, X);
    return 0;
}