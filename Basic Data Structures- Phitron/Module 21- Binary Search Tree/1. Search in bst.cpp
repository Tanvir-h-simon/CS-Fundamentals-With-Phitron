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
    cout << "Enter root value(-1 for NULL): ";
    int value;
    cin >> value;

    if (value  == -1) {
        return NULL;
    }

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left and right child of " << temp->value << " (-1 for NULL): ";
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

bool search(Node* root, int x) { // O(h), h = height of binary tree
    if (!root) return false;

    if (root->value == x) return true;
    // return search(root->left, x) && search(root->right, x);
    if (root->value > x) return search(root->left, x); 
    else return search(root->right, x);    
}


int main() {
    Node* root = input();

    cout << "Enter a node value to search in the BST: ";
    int value;
    cin >> value;
    // if (search(root, value)) 
    //     cout << "Found\n";
    // else 
    //     cout << "Not found\n";
    cout << boolalpha << search(root, value);

    return 0;
}