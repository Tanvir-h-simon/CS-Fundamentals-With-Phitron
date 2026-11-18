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

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftNode, rightNode;
        cin >> leftNode >> rightNode;

        if (leftNode != -1) {
            temp->left = new Node(leftNode);
            q.push(temp->left);
        }

        if (rightNode != -1) {
            temp->right = new Node(rightNode);
            q.push(temp->right);
        }
    }
    return root;
}

void printPostorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->value << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        } 
    }
}

int sum (Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 0; // If it's a leaf node, don't include it in sum

    // It's a non-leaf node, include its value and recursively sum children
    return root->value + sum(root->left) + sum(root->right);
}

int main() {
    Node* root = input();
    printPostorder(root);
    cout << sum(root);
    return 0;
}