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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        // use a queue for bfs
        queue<TreeNode *> Q;
        Q.push(root);
        // while queue is not empty keep traversing level by level
        while (!Q.empty())
        {
            int sz = Q.size();
            int count = 0;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = Q.front();
                Q.pop();
                // push the first element in the result
                if (count == 0)
                {
                    result.push_back(temp->val);
                }
                if (temp->right)
                {
                    Q.push(temp->right);
                }
                if (temp->left)
                {
                    Q.push(temp->left);
                }
                count++;
            }
        }
        return result;
    }
};

void printVec(vector<int> result)
{
    for (int r : result)
    {
        cout << r << " ";
    }
    cout << endl;
}

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
    cout << "The right side view of the given tree is " << endl;
    printVec(mySol.rightSideView(root));
    return 0;
}