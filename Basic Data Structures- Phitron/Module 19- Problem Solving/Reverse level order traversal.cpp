#include <iostream>
#include <queue>
#include <vector>
#include <utility>
// #include <algorithm>
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

        cout << "Enter left and right child of " << current->value << " (-1 for NULL): ";
        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        if (leftValue != -1) {
            current->left = new Node(leftValue);
            q.push(current->left);
        }
        if (rightValue != -1) {
            current->right = new Node(rightValue);
            q.push(current->right);
        }
    }
    return root;
}

void levelorderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        } 
    } 
}

vector<int> reverselevelorderTraversal(Node* root) {
    if (root == NULL) return vector<int>();

    vector<int> v;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        // cout << current->value << " ";
        v.push_back(current->value);

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        } 
    } 
    // reverse(v.begin(), v.end());
    return v;
}

int main() {
    cout << "Enter the root node value: ";
    int value;
    cin >> value;
    Node* root = buildTree(value);

    cout << "\nLevel order traversal: ";
    levelorderTraversal(root);

    cout << "\nReverse level order: ";
    vector<int> v = reverselevelorderTraversal(root);
    int size = v.size();
    for (int i = size - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    return 0;
}