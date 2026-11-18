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

int totalNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftCount = totalNodes(root->left);
    int rightcount = totalNodes(root->right);
    return leftCount + rightcount + 1; 
}

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int leftCount = countLeafNodes(root->left);
    int rightcount = countLeafNodes(root->right);
    return leftCount + rightcount; 
}

int main() {
    Node* root = buildTreeBFS();
    cout << "\nLevel order traversal: ";
    printPostorder(root);

    int numberOfNodes = totalNodes(root);
    cout << "\nTotal leaf nodes = " << numberOfNodes << endl;

    int totalLeafNodes = countLeafNodes(root);
    cout << "Total leaf nodes = " << totalLeafNodes << endl;

    return 0;
}