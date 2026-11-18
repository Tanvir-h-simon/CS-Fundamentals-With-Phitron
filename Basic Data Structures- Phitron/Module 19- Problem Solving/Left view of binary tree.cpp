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

// void leftView(Node* root) {
//     if (root == NULL) return;

//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; i++) {
//             Node* current = q.front();
//             q.pop();

//             if (i == 0) {
//                 cout << current->value << " ";
//             }

//             if (current->left != NULL) q.push(current->left);
//             if (current->right != NULL) q.push(current->right);
//         }

//     }
// }

vector<int> leftView(Node* root) {
    vector<int> v;
    bool freqArray[3005] = {false}; // To track the node is taken or not in the specific level. Default frequency array value is false

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        auto parent = q.front();
        q.pop();

        Node* node = parent.first;
        int level = parent.second;
        
        if (freqArray[level] == false) {
            v.push_back(node->value);
            freqArray[level] = true;
        }

        if (node->left != NULL) q.push(make_pair(node->left, level + 1));
        if (node->right != NULL) q.push(make_pair(node->right, level + 1));

        // Right view of binary tree
        if (node->right != NULL) q.push(make_pair(node->right, level + 1));
        if (node->left != NULL) q.push(make_pair(node->left, level + 1));
    }
    return v;
}

int main() {
    cout << "Enter number of test cases: ";
    int t;
    cin >> t; // Test cases

    while (t--) {
        cout << "Enter the root node value: ";
        int value;
        cin >> value;
        Node* root = buildTree(value);
        // levelorderTraversal(root);
        vector<int> v = leftView(root);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}