#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    // do a post order traversal, recursively visit left nodes, then right nodes, and finally root
    // swap the roots right and left node 
    void swap(TreeNode* root) {
        if (!root) return;
        swap(root->left);
        swap(root->right);
        TreeNode* newNode = root->left;
        root->left = root->right;
        root->right = newNode;
    }
    public:
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};

void printBSTPreorder(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    printBSTPreorder(root->left);
    printBSTPreorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << "Original Tree ";
    printBSTPreorder(root);
    cout << endl;
    cout << "New Tree ";
    printBSTPreorder(sol.invertTree(root));
    cout << endl;
    return 0;
}