#include <iostream>
#include <queue>
#include <vector>
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

vector<int> printLevelorder(Node* root) {
    vector<int> v;
    if (!root) return v;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        v.push_back(current->value);

        // if (f->left != NULL) {
        //     q.push(f->left);
        // }
        // if (f->right != NULL) {
        //     q.push(f->right);
        // } 

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    return v;
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    vector<int> level = printLevelorder(root);
    for (int value : level) 
        cout << value << " ";
    cout << endl;

    return 0;
}