#include <iostream>
#include <vector>
#include <stack>

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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        stack<TreeNode *> treeNodes;
        treeNodes.push(root);
        while (!treeNodes.empty())
        {
            TreeNode *curr = treeNodes.top();
            treeNodes.pop();
            if (curr->right)
                treeNodes.push(curr->right);
            if (curr->left)
                treeNodes.push(curr->left);
            if (!treeNodes.empty())
                curr->right = treeNodes.top();
            curr->left = NULL;
        }
    }
};

void PrintInorder(TreeNode *root)
{
    if (!root) {
        cout << "NULL ";
        return;
    }
    PrintInorder(root->left);
    cout << root->val << " ";
    PrintInorder(root->right);
}

int main()
{
    Solution mySol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    PrintInorder(root);
    cout << endl;
    mySol.flatten(root);
    PrintInorder(root);
    cout << endl;
    return 0;
}