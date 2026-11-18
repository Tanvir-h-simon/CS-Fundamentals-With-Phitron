#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
class BinaryTree {
public:
    Node<T>* buildTree() {
        T value;
        cin >> value;

        if (value == -1) return NULL;

        Node<T>* root = new Node<T>(value);
        cout << "Enter left child of " << value << " (-1 for NULL): ";
        root->left = buildTree();
        cout << "Enter right child of " << value << " (-1 for NULL): ";
        root->right = buildTree();

        return root;
    }

    void inorder(Node<T>* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }

    void preorder(Node<T>* root) {
        if (!root) return;
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node<T>* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }

    void levelOrder(Node<T>* root) {
        if (!root) return;
        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            cout << current->value << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
};

int main() {
    BinaryTree<int> tree;

    cout << "Enter root value (-1 for NULL): ";
    Node<int>* root = tree.buildTree();

    cout << "Inorder: ";
    tree.inorder(root);
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(root);
    cout << endl;

    cout << "Level order: ";
    tree.levelOrder(root);
    cout << endl;

    return 0;
}