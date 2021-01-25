#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // various initialization strategies
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
    int get_height(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(get_height(root->left), get_height(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // if no root is present the tree is balanced
        if (!root)
            return true;
        // get the left and right heights
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        // check the balanced conditions
        return isBalanced(root->left) && isBalanced(root->right) && abs(left_height - right_height) <= 1;
    }
};

int main()
{
    Solution mySol;
    TreeNode *root = new TreeNode(5, new TreeNode(9), new TreeNode(20));
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    string isBalanced = mySol.isBalanced(root) ? "Yes" : "No";
    cout << "Is the tree [5, 9, 20, null, null, 15, 7] ? ";
    cout << isBalanced << endl;
    TreeNode *root2 = new TreeNode(1, new TreeNode(2), new TreeNode(2));
    root2->left->left = new TreeNode(3, new TreeNode(4), new TreeNode(4));
    root2->left->right = new TreeNode(4);
    isBalanced = mySol.isBalanced(root2) ? "Yes" : "No";
    cout << "Is the tree [1, 2, 2, 4, 3, null, null, 4, 4] ? ";
    cout << isBalanced << endl;
    return 0;
}