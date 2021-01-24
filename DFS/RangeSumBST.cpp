#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
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
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        int sum = 0;
        // if the root value is within range, set sum to root value
        if (root->val >= low && root->val <= high)
            sum = root->val;
        // add sum of left side and right side to the current sum
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};

int main()
{
    Solution mySol;
    TreeNode *root = new TreeNode(10, new TreeNode(5), new TreeNode(15));
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    cout << "The range sum of the BST between 7 and 15: " << mySol.rangeSumBST(root, 7, 15) << endl;
    return 0;
}