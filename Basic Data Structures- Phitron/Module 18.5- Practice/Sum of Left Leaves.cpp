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

// int sumOfLeafNodes (Node* root) {
//     if (!root) return 0;
//     if (!root->left && !root->right) return root->value;

//     // Recursively get sum from left and right subtrees
//     return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
// }
int sumOfLeafNodes (Node* root, bool isLeft = false) {
    if (!root) return 0;
    if (!root->left && !root->right && isLeft) return root->value;

    // Recursively get sum from left and right subtrees
    return sumOfLeafNodes(root->left, true) + sumOfLeafNodes(root->right, false);
}

int sumOfRightNodes (Node* root, bool isRight = false) {
    if (!root) return 0;
    if (!root->left && !root->right && isRight) return root->value;

    // Recursively get sum from left and right subtrees
    return sumOfLeafNodes(root->left, false) + sumOfLeafNodes(root->right, true);
}

Node* buildTreeBFS () {
    cout << "Enter value of root node (-1 for NULL): ";
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    } 
    
    Node* root = new Node(value); // Create the root node and push into queue
    queue<Node*> q;
    q.push(root); 

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter the left and right node value of " << temp->value << " (-1 for NULL): ";
        int leftNode, rightNode;
        cin >> leftNode >> rightNode;

        if (leftNode != - 1) {
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

void printPostorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->value << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = buildTreeBFS();
    cout << "Level order traversal: ";
    printPostorder(root);

    int sum = sumOfLeafNodes(root);
    cout << "\nSum = " << sum << endl;

    return 0;
}