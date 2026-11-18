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

// // Left → Root → Right
// Iterative Inorder traversal:
// vector<int> printInorder(Node* root) {
//     vector<int> v;

//     stack<Node*> st;
//     Node* current = root;

//     while (current != NULL || !st.empty()) {
//         while (current != NULL) { // Move left
//             st.push(current);
//             current = current->left;
//         }
//         current = st.top();
//         st.pop();
//         v.push_back(current->value);

//         // Move to right subtree
//         current = current->right;
//     }
//     return v;
// }

void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Recursion on left subtree
    printInorder(root->left);
    // Print the root(current) node
    cout << root->value << " ";
    // Recursion on right subtree
    printInorder(root->right);
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

    printInorder(root);

    // vector<int> v = printInorder(root); 

    // for (int value : v) {
    //     cout << value << " ";
    // }

    return 0;
}