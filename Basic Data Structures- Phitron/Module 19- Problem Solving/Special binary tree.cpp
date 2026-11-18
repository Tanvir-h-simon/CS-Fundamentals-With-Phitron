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

bool isSpecialBinaryTree(Node* root) {
    if (root == NULL) return true;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))  return false;

    // return isSpecialBinaryTree(root->left) && isSpecialBinaryTree(root->right);

    bool leftSubtree = isSpecialBinaryTree(root->left);
    bool rightSubtree = isSpecialBinaryTree(root->right);
    // return leftSubtree == true && rightSubtree == true;
    return leftSubtree && rightSubtree; // The left subtree and the right subtree must be special(true) for the whole tree to be special(true).
}

int main() {
    cout << "Enter the number of test cases: ";
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        cout << "Enter the root node value: ";
        int value;
        cin >> value;
        Node* root = buildTree(value);

        cout << "\nLevel order traversal: ";
        levelorderTraversal(root);

        cout << "\nIs Special: " << boolalpha << isSpecialBinaryTree(root) << endl;
    }

    return 0;
}