#include <iostream>
#include <vector>
#include <stack>
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

// // Root → Left → Right
// Iterative Preorder traversal:
// vector<int> printPreorder(Node* root) {
//     vector<int> v;
//     if (!root) return v;

//     stack<Node*> st;
//     st.push(root);

//     while (!st.empty()) {
//         Node* current = st.top();
//         st.pop();

//         v.push_back(current->value);

//         if (current->right != NULL) { 
//             st.push(current->right);
//         } 
//         if (current->left != NULL) { // Top value of the stack and push into vector first
//             st.push(current->left);
//         }
//     }
//     return v;
// }

void printPreorder(Node* root) {
    if (root == NULL) {
        return;
    }
    // Print the root(current) node
    cout << root->value << " ";
    // Recursion on left subtree
    printPreorder(root->left);
    // Recursion on right subtree
    printPreorder(root->right);
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
    a->right = d;
    b->right = e;

    printPreorder(root);

    // vector<int> v = printPreorder(root);

    // for (int value : v) {
    //     cout << value << " ";
    // }
    // cout << endl;

    return 0;
}