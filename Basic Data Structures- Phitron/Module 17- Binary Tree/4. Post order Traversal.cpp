#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

// vector<int> printPostorder(Node* root) {
//     vector<int> v;
//     if (!root) return v;

//     stack<Node*> st1, st2;
//     st1.push(root);

//     while (!st1.empty()) {
//         Node* current = st1.top(); 
//         st1.pop();
//         st2.push(current);

//         if (current->left != NULL) { 
//             st1.push(current->left); 
//         }
//         if (current->right != NULL) { 
//             st1.push(current->right);
//         }
//     }

//     while (!st2.empty()) {
//         v.push_back(st2.top()->value);
//         st2.pop();
//     }

//     return v;
// }

void printPostorder(Node* root) {
    if (root == NULL) {
        return;
    }
    // Recursion on left subtree
    printPostorder(root->left);
    // Recursion on right subtree
    printPostorder(root->right);
    // Deal with the root node
    cout << root->value << " ";
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    printPostorder(root);

    // vector<int> v = printPostorder(root);
    // for (int val : v) 
    //     cout << val << " ";
    // cout << endl;

    return 0;
}