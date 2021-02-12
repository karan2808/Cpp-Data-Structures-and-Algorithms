#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int ans = 0;
    void inOrder(TreeNode *root, int &k)
    {
        if (!root)
            return;
        inOrder(root->left, k);
        k--;
        if (k == 0)
            ans = root->val;
        inOrder(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5, new TreeNode(3), new TreeNode(6));
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(8);
    Solution mySol;
    cout << "The 4 th smallest element in the BST is " << mySol.kthSmallest(root, 4) << endl;
    return 0;
}