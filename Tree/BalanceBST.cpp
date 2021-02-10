#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree Node
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> nodes;
    void inorder(TreeNode* root) {
        if(!root) return;
        // do an inorder traversal, keep adding the node value to a nodes array
        // then all nodes will be in a sorted order
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* buildTree(int start, int end) {
        // base case, if start pointer exceeds end, return null
        if(start > end) return NULL;
        // get the middle node, this will be the new root
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode(nodes[mid]);
        // split the nodes into two halves and then keep building the tree
        node->left = buildTree(start, mid-1);
        node->right = buildTree(mid+1, end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // do an inorder traversal of the tree and add the nodes to nodes array
        inorder(root);
        root = NULL;
        int n = nodes.size();
        if(n == 1) return root;
        root = buildTree(0, n-1);
        // build the tree,
        return root;
    }
};
void printBSTPreorder(TreeNode* root) {
    if (!root) {
        cout << "NULL ";
        return;
    };
    cout << root->val << " ";
    printBSTPreorder(root->left);
    printBSTPreorder(root->right);
}

int main() {    
    Solution mySol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    cout << "The original tree is ";
    printBSTPreorder(root);
    cout << endl;
    TreeNode* newRoot = mySol.balanceBST(root);
    cout << "The new tree is ";
    printBSTPreorder(newRoot);
    cout << endl;
    return 0;
}