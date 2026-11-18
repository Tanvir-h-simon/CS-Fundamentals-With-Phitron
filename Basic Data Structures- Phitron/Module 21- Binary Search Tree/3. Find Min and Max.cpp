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

Node* inputTree() {
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

int findMin(Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL) {
        root = root->left;
    }

    return root->value;
}

int findMax(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL) {
        root = root->right;
    }
    return root->value;
}

void printLevelorder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->value << " ";
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        } 
    }
}

void printInorder(Node* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

int main() {
    Node* root = inputTree();
    cout << "Level order traversal: "; 
    printLevelorder(root);
    cout << endl;
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;

    cout << "Minimum value: ";
    cout << findMin(root);
    cout << endl;
    cout << "Maximum value: ";
    cout << findMax(root);

    return 0;
}