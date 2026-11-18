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

int calcHeight(Node* root, int &diameter) {
    if (root == NULL) return 0;

    int leftHeight = calcHeight(root->left, diameter); // Height of the left subtree
    int rightHeight = calcHeight(root->right, diameter); // Height of the right subtree
    // int maxHeight = max(leftHeight, rightHeight) + 1;

    // Diameter = path through left + right
    int currentDiameter = leftHeight + rightHeight;
    diameter = max(diameter, currentDiameter); // Maximum diameter

    return max(leftHeight, rightHeight) + 1; // Return height
}

int main() {
    cout << "Enter the root node value: ";
    int value;
    cin >> value;
    Node* root = buildTree(value);

    cout << "\nLevel order traversal: ";
    levelorderTraversal(root);

    int diameter = 0;
    calcHeight(root, diameter);

    cout << "\nDiameter of the tree: " << diameter << endl;

    return 0;
}