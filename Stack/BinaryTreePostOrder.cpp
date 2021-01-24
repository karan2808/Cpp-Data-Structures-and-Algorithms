#include <iostream>
#include <vector>
#include <stack>

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
    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrder;
        // if root is null, return empty vector
        if (!root)
            return postOrder;
        // use a stack for storing seen nodes
        stack<TreeNode *> stk;
        TreeNode *current = root;
        // iterate till you reach a leaf node or there are no elements in the stack
        while (current || stk.size())
        {
            // if current node has a left node, push current on to stack, visit the left node
            if (current->left)
            {
                stk.push(current);
                current = current->left;
                // set the current nodes left as null
                stk.top()->left = nullptr;
            }
            // do the same if current has a right node
            else if (current->right)
            {
                stk.push(current);
                current = current->right;
                stk.top()->right = nullptr;
            }
            else
            {
                // at the leaf, append to stack
                postOrder.push_back(current->val);
                // if the stack is not empty
                if (!stk.empty())
                {
                    // go back to the previous node
                    current = stk.top();
                    // remove it from the stack
                    stk.pop();
                }
                else
                {
                    // all nodes have been traversed
                    current = nullptr;
                }
            }
        }
        return postOrder;
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
    Solution mySol;
    TreeNode *root1 = new TreeNode(5, new TreeNode(6), new TreeNode(7));
    root1->left->left = new TreeNode(-1, new TreeNode(2), new TreeNode(3));
    root1->left->right = new TreeNode(8);
    TreeNode *root2 = new TreeNode(9, new TreeNode(-1), new TreeNode(2));
    root2->right->left = new TreeNode(5, new TreeNode(6), new TreeNode(7));
    root2->left->right = new TreeNode(8);
    vector<int> result1 = mySol.postorderTraversal(root1);
    vector<int> result2 = mySol.postorderTraversal(root2);
    cout << "Post Order Traversal of Root 1 is: ";
    printVec(result1);
    cout << "Post Order Traversal of Root 2 is: ";
    printVec(result2);
    return 0;
}