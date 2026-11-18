#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node (int value) {
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(int value) {
    if (value == -1) return NULL;
    
    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // cout << "Enter left and right child of " << current->value << " (-1 for NULL): ";
        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        if (leftValue != -1) {
            // Node* leftNode = new Node(leftValue);
            // current->left = leftNode;
            // q.push(leftNode);   
            current->left = new Node(leftValue);
            q.push(current->left);
        }
        if (rightValue != -1) {
            // Node* rightNode = new Node(rightValue);
            // current->right = rightNode;
            // q.push(rightNode);
            current->right = new Node(rightValue);
            q.push(current->right);
        }
    }
    return root;
}

// void levelorderTraversal(Node* root) {
//     if (root == NULL) return;

//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         cout << current->value << " ";

//         if (current->left != NULL) {
//             q.push(current->left);
//         }
//         if (current->right != NULL) {
//             q.push(current->right);
//         } 
//     } 
// }

bool isPresent(Node* root, int X) {
   if (root == NULL) return false;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->value == X) {
            return true; // Found
        }

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        } 
    } 
    return false;
}

// bool isPresent(Node* root, int X) {
//     if (root == NULL) return false; // Base case
//     if (root->value == X) return true;
    
//     bool l = isPresent(root->left, X);
//     bool r = isPresent(root->right, X);

//     if (l || r) return true;
//     else return false;
// }

int main() {
    // cout << "Enter the root node value: ";
    int value;
    cin >> value;
    Node* root = buildTree(value);
    // levelorderTraversal(root);
    
    // cout << "Enter the value: ";
    int X;
    cin >> X;
    // cout << isPresent(root, X) << endl;
    cout << boolalpha << isPresent(root, X) << endl;
    return 0;
}