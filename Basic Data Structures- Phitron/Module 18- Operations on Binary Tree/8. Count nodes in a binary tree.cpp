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

int printLevelOrder(Node* root) {
    int count = 0;
    if (!root) return -1;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->value << " ";
        count++;

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        } 
    }
    return count;
}

// int countNodes(Node* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int leftCount = countNodes(root->left);
//     int rightcount = countNodes(root->right);
//     return leftCount + rightcount + 1; 
// }

int main() {
    Node* root = buildTreeBFS();
    cout << "\nLevel order traversal: ";
    int totalNodes = printLevelOrder(root);
    cout << "\nTotal nodes: " << totalNodes << endl;

    return 0;
}