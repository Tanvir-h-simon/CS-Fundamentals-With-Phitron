#include <iostream>
#include <queue>
#include <utility>
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
        
        int leftValue, rightValue;
        cout << "Enter the left and right child of " << current->value << ": ";
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

void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

int searchNodeLevel(Node* root, int x) {
    if (!root) return -1;

    queue<pair<Node*, int>> q;
    // q.push(make_pair(root, 0));
    q.push({root, 0}); // Store node, level

    while(!q.empty()) {
        // Node* current = q.front();
        auto current = q.front();
        q.pop();

        Node* node = current.first;
        int level = current.second;

        if (node->value == x) return level; // Found

        if (node->left != NULL) 
        // q.push(make_pair(node->left, level + 1)); 
        q.push({node->left, level + 1});

        if (node->right != NULL) 
        // q.push(make_pair(node->right, level + 1));
        q.push({node->right, level + 1});
    }

    return -1; // Not found
}



int main() {
    cout << "Enter the number of test cases: ";
    int n;
    cin >> n;
    
    while (n--) {
        cout << "Enter the root value(-1 for NULL): ";
        int value;
        cin >> value;
        Node* root = buildTree(value);

        cout << "Node value to search: ";
        int x;
        cin >> x;

        cout << "Level order traversal: ";
        levelOrder(root);

        cout << "\nNode found at level: " << searchNodeLevel(root, x) << endl;
    }
    
    return 0;
}