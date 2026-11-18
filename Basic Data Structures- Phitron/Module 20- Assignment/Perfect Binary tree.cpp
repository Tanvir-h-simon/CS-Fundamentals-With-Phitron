#include <iostream>
#include <queue>
#include <cmath>
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

int totalNodes(Node* root) {
    if (root == NULL) return 0;

    int leftCount = totalNodes(root->left);
    int rightcount = totalNodes(root->right);

    return leftCount + rightcount + 1; 
}

int maxHeight(Node* root) {
    if (!root) return 0;

    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

string isPerfectBinary(Node* root) {
    int expectedNodes = pow(2, maxHeight(root)) - 1;
    if (totalNodes(root) == expectedNodes) {
        return "YES";
    } else {
        return "NO";
    }
}

// void printLevelOrder(Node* root) {
//     if (!root) return;
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();
//         cout << temp->value << " ";

//         if (temp->left) {
//             q.push(temp->left);
//         }
//         if (temp->right) {
//             q.push(temp->right);
//         } 
//     }
// }
 
int main() {
    Node* root = input();
    cout << isPerfectBinary(root);
    return 0;
}