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

Node* buildTreeBFS() {
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
        int l, r;
        cin >> l >> r;

        if (l != -1) {
            temp->left = new Node(l);
            q.push(temp->left);
        }

        if (r != -1) {
            temp->right = new Node(r);
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

int maxHeight(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;

    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);

    return max(leftHeight, rightHeight) + 1; // Maximum height + 1
}

int main() {
    Node* root = buildTreeBFS();
    cout << "\nLevel order traversal: ";
    printPostorder(root);

    cout << "\nHeight = " << maxHeight(root) << endl;

    return 0;
}