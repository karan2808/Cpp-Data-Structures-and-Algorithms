#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = nullptr;
        right = nullptr;
        val = 0;
    }
    TreeNode(int val)
    {
        left = nullptr;
        right = nullptr;
        this->val = val;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->left = left;
        this->right = right;
        this->val = val;
    }
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // store values from preorder traversal
        vector<int> preorder;
        if (!root) return preorder;
        // push the nodes onto stack while traversing
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            root = nodes.top();
            nodes.pop();
            // visit root node
            preorder.push_back(root->val);
            // if a right node is present push it on to stack
            if (root->right) {
                nodes.push(root->right);
            }
            // if a left node is present push it on to stack
            // left node is pushed after right so that it gets visited before it.
            if (root->left) {
                nodes.push(root->left);
            }
        }
        return preorder;
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
    vector<int> result1 = mySol.preorderTraversal(root1);    
    vector<int> result2 = mySol.preorderTraversal(root2);
    cout << "Preorder Traversal of Root 1 is: ";
    printVec(result1);
    cout << "Preorder Traversal of Root 2 is: ";    
    printVec(result2);
    return 0;
}