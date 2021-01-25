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

class Solution {
    int findMax(TreeNode* root, int &result) {
        if (!root) return 0;
        int left = findMax(root->left, result);
        int right = findMax(root->right, result);
        // we can go straight down towards left or right, if the net sum decreases, we keep the current value
        int maxStraight = max(max(left, right) + root->val, root->val);
        // we can also have a curved path from left path, current node and right path
        int maxCurved = max(left + right + root->val, maxStraight);
        // update the result
        result = max(result, maxCurved);
        // finally since we need to go back from the current node, we can only return the straight path sum
        return maxStraight;
    }
    public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int result = INT_MIN;
        findMax(root, result);
        return result;
    }
};

int main() {
    Solution mySol;
    TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(2));
    root1->left->left = new TreeNode(3, new TreeNode(4), new TreeNode(4));
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(1, new TreeNode(0), new TreeNode(10));
    cout << "The max path sum for [1, 2, 2, 3, 4, 1, null, 4, 4, 0, 10] is: " << mySol.maxPathSum(root1) << endl;
    return 0;
}