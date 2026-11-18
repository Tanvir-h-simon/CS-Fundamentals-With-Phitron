#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // The diameter at this node is leftHeight + rightHeight
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of this node
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of the tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}