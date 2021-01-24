#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// definition of a binary tree node
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
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> result;
        TreeNode *current = root;
        // while a node is present or there are elements on the stack
        while (current || stk.size())
        {
            // keep pushing elements on the stack while traversing left
            while (current)
            {
                stk.push(current);
                current = current->left;
            }
            // get the top element from the stack, this will be the left most element
            current = stk.top();
            stk.pop();
            // visit the node
            result.push_back(current->val);
            // go right
            current = current->right;
        }
        return result;
    }
};

void printVec(vector<int> values)
{
    for (int val : values)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root1 = new TreeNode(5, new TreeNode(6), new TreeNode(7));
    root1->left->left = new TreeNode(-1, new TreeNode(2), new TreeNode(3));
    root1->left->right = new TreeNode(8);
    TreeNode *root2 = new TreeNode(9, new TreeNode(-1), new TreeNode(2));
    root2->right->left = new TreeNode(5, new TreeNode(6), new TreeNode(7));
    root2->left->right = new TreeNode(8);
    Solution mySol;
    cout << "Inorder traversal of tree with root1: ";
    vector<int> values_root1 = mySol.inorderTraversal(root1);
    printVec(values_root1);
    cout << "Inorder traversal of tree with root2: ";
    vector<int> values_root2 = mySol.inorderTraversal(root2);
    printVec(values_root2);
    return 0;
};