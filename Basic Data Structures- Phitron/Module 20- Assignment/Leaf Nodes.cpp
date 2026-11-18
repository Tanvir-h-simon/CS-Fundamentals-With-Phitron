#include <iostream>
#include <queue>
#include <algorithm>
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

Node* input() {
    int value;
    cin >> value;
    if (value == -1) return NULL;

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftNode, rightNode;
        cin >> leftNode >> rightNode;
        if (leftNode != -1) {
            current->left = new Node(leftNode);
            q.push(current->left);
        }
        if (rightNode != -1) {
            current->right = new Node(rightNode);
            q.push(current->right);
        }
    }

    return root;
}

void printLeafNode(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    vector<int> leafValues; // Store the leaves values in the vector

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left && !temp->right) {
            // cout << temp->value << " ";
            leafValues.push_back(temp->value);
        }

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    // Sort the leaves values in ascending order
    // sort(leafValues.begin(), leafValues.end());

    // Sort the leaves values in descending order
    sort(leafValues.begin(), leafValues.end(), greater<int>());
    

    for (int data : leafValues) {
        cout << data << " ";
    }
}
 
int main() {
    Node* root = input();
    printLeafNode(root);
    return 0;
}