#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 1;
        // use a queue for bfs
        queue<TreeNode *> Q;
        Q.push(root);
        // while elements in the queue or while leaf has not been reached
        while (Q.size() || root)
        {
            int sz = Q.size();
            // go through all elements in the queue
            for (int i = 0; i < sz; i++)
            {
                TreeNode *current = Q.front();
                Q.pop();
                if (current && !current->left && !current->right)
                {
                    return depth;
                }
                // push the leaf nodes to the queue
                if (current->left)
                    Q.push(current->left);
                if (current->right)
                    Q.push(current->right);
            }
            depth += 1;
        }
        return depth;
    }
};

int main()
{
    Solution mySol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(17);
    root->right->right = new TreeNode(19);
    root->right->left = new TreeNode(21);
    root->right->right->left = new TreeNode(25);
    cout << "The minimum depth of the given tree is " << mySol.minDepth(root) << endl;
    return 0;
}