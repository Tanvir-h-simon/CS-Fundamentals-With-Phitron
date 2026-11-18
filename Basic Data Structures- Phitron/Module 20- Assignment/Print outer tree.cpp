#include <iostream>
#include <queue>
#include <vector>
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

// void printLeftBoundary(Node* root) {
//     Node* current = root->left;
//     while (current) {
//         if (!current->left && !current->right)
//             cout << current->value << " ";

//         if (current->left) current = current->left;
//         else current = current->right;
//     }
// }

void printLeftBoundary(Node* root) {
    if (!root->left) return;
    
    vector<int> v;
    Node* current = root->left;
    
    while (current) {
        v.push_back(current->value);
        if (current->left) current = current->left;
        else current = current->right;
    }
    
    // Print in reverse order
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

// void printLeaves(Node* root) {
//     if (!root) return;
//     if (!root->left && !root->right) {
//         cout << root->value << " ";
//         return;
//     }

//     printLeaves(root->left);
//     printLeaves(root->right);
// }

// void printRightBoundary(Node* root) {
//     vector<int> v;
//     Node* current = root->right;
//     while (current) {
//         if (!current->left && !current->right)
//             v.push_back(current->value);

//         if (current->right) current = current->right;
//         else current = current->left;
//     }

//     for (int i = v.size() - 1; i >= 0; i--) {
//         cout << v[i] << " ";
//     }
// }

void printRightBoundary(Node* root) {
    if (!root->right) return;
    
    Node* current = root->right;
    while (current) {
        cout << current->value << " ";
        if (current->right) current = current->right;
        else current = current->left;
    }
}

int main() {
    Node* root = input();
    if (!root) return 0;

    // cout << root->value << " ";
    // printLeftBoundary(root);
    // printLeaves(root);
    // printRightBoundary(root);

    printLeftBoundary(root);
    cout << root->value << " ";
    printRightBoundary(root);

    return 0;
}