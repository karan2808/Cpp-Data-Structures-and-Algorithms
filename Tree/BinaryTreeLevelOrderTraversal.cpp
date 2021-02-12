#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        // use q queue to store the tree nodes level by level
        queue<TreeNode *> Queue;
        Queue.push(root);

        // while queue is not empty, append nodes to result
        while (!Queue.empty())
        {
            TreeNode *curr;
            vector<int> currentLevel;
            int sz = Queue.size();
            for (int i = 0; i < sz; i++)
            {
                // get the queue front and pop that element from the queue
                curr = Queue.front();
                Queue.pop();
                // push the current val to current level vector
                currentLevel.push_back(curr->val);
                // append the left node and the right node to the queue, so they get visited next
                if (curr->left)
                    Queue.push(curr->left);
                if (curr->right)
                    Queue.push(curr->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

void printVec(vector<vector<int>> levels)
{
    for (vector<int> level : levels)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(5, new TreeNode(3), new TreeNode(6));
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8, new TreeNode(7), new TreeNode(8));
    root->right->right->left->left = new TreeNode(6);
    root->right->right->left->right = new TreeNode(8);
    Solution mySol;
    vector<vector<int>> result = mySol.levelOrder(root);
    printVec(result);
    return 0;
}