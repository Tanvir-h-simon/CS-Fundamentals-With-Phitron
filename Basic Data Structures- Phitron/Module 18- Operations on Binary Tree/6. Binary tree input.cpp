#include <iostream>
#include <queue>
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

// Recursive input (DFS style)
Node* buildTreeDFS() {
    cout << "Enter value(-1 for NULL): ";
    int value;
    cin >> value;
    if (value == -1) {
        return NULL;
    }

    Node* root = new Node(value);
    root->left = buildTreeDFS();
    root->right = buildTreeDFS();

    return root;
}

Node* buildTreeBFS() {
    cout << "Enter value(-1 for NULL): ";
    int value;
    cin >> value;
    if (value  == -1) {
        return NULL;
    }

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << "Enter left and right child of " << current->value << " (-1 for NULL): ";
        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        // Node *leftNode, *rightNode;
        // if (leftValue == -1) leftNode = NULL;
        // else leftNode = new Node(leftValue);

        // if (rightValue == -1) rightNode = NULL;
        // else rightNode = new Node(rightValue);

        // current->left = leftNode;
        // current->right = rightNode;
        
        // if (current->left) {
        //     q.push(current->left);
        // }
        // if (current->right) {
        //     q.push(current->right);
        // }
        if (leftValue != -1) {
            current->left = new Node(leftValue);
            q.push(current->left);
        }

        if (rightValue != -1) {
            current->right = new Node(rightValue);
            q.push(current->right);
        }    
    }

    // while (!q.empty()) {
        //     Node* current = q.front();
        //     q.pop();

            // // Left child
            // cout << "Enter left child of " << current->value << " (-1 for NULL): ";
            // cin >> value;
            // if (value != -1) {
            //     current->left = new Node(value);
            //     q.push(current->left);
            // }

            // // Right child
            // cout << "Enter right child of " << current->value << " (-1 for NULL): ";
            // cin >> value;
            // if (value != -1) {
            //     current->right = new Node(value);
            //     q.push(current->right);
            // }
        // } 
    return root;
}

// // BFS Style:
// Node* buildTree() {
//     int value;
//     cout << "Enter node value (-1 for null): ";
//     cin >> value;
    
//     if (value == -1) {
//         return nullptr;
//     }
    
//     Node* root = new Node(value);
//     cout << "Enter left child of " << value << endl;
//     root->left = createTree();
    
//     cout << "Enter right child of " << value << endl;
//     root->right = createTree();
    
//     return root;
// }

void printPostorder(Node* root) {
    if (!root) return;
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

int main() {
    // Node* root = new Node(10);
    // Node* a = new Node(20);
    // Node* b = new Node(30);
    // Node* c = new Node(40);
    // Node* d = new Node(50);
    // Node* e = new Node(60);

    // root->left = a;
    // root->right = b;
    // a->left = c;
    // b->left = d;
    // b->right = e;

    // Node* root = buildTreeDFS();
    // printPreorder(root);

    int value;
    cin >> value;
    Node* root = buildTreeBFS();

    Node* root = buildTreeBFS();
    cout << "\nLevel order traversal: ";
    printPostorder(root);

    return 0;
}