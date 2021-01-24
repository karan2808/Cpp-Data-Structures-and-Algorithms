#include <iostream>
#include <unordered_map>

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

// time complexity: 2 ^ n, evaluating all possible combinations for each node. Space complexity is 2 ^ n as well due to the recursion stack.

class Solution
{
    unordered_map<TreeNode *, int> NodeMap;

public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        // if root exists in node map, return it
        if (NodeMap.find(root) != NodeMap.end())
            return NodeMap[root];

        // calculate the profit from root and its grand children
        int profitRootGC = root->val;
        if (root->left)
            profitRootGC += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            profitRootGC += rob(root->right->left) + rob(root->right->right);

        // calculate profit from roots children
        int profitC = rob(root->left) + rob(root->right);

        // get the max of the two and store it in the map
        NodeMap[root] = max(profitRootGC, profitC);
        return NodeMap[root];
    }
};

int main()
{
    Solution mySol;
    TreeNode *root = new TreeNode(3, new TreeNode(2), new TreeNode(3));
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << "The max amount the thief can rob given the tree: ";
    cout << "[3, 2, 3, null, 3, null, 1] ";
    cout << mySol.rob(root) << endl;
    return 0;
}