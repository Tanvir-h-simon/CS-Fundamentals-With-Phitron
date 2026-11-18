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

Node* sortedArrayToBST(int arr[], int size, int leftIndex, int rightIndex) {
    if (leftIndex > rightIndex) return NULL;

    int midIndex = (leftIndex + rightIndex) / 2;
    Node* root = new Node(arr[midIndex]);

    // Node* leftSubtree = sortedArrayToBST(arr, size, leftIndex, midIndex - 1);
    // root->left = leftSubtree;
    // Node* rightSubtree = sortedArrayToBST(arr, size, midIndex + 1, rightIndex);
    // root->right = rightSubtree;
    root->left = sortedArrayToBST(arr, size, leftIndex, midIndex - 1);
    root->right = sortedArrayToBST(arr, size, midIndex + 1, rightIndex);
    
    return root;
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

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i]; // Sorted array
    }

    Node* root = sortedArrayToBST(arr, size, 0, size - 1);

    cout << "BST: ";
    printLevelorder (root);
    return 0;
}