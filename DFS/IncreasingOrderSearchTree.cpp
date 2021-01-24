#include <iostream>
#include <vector>
#include <stack>

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

vector<int> preorderTraversal(TreeNode *root)
{
    // store values from preorder traversal
    vector<int> preorder;
    if (!root)
        return preorder;
    TreeNode *current = root;
    // push the nodes onto stack while traversing
    stack<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        current = nodes.top();
        nodes.pop();
        // visit root node
        preorder.push_back(current->val);
        // if a right node is present push it on to stack
        if (current->right)
        {
            nodes.push(current->right);
        }
        // if a left node is present push it on to stack
        // left node is pushed after right so that it gets visited before it.
        if (current->left)
        {
            nodes.push(current->left);
        }
    }
    return preorder;
}

class Solution
{
    TreeNode *current;
    // do an inorder traversal of the tree
    void inOrder(TreeNode *node)
    {
        if (!node)
            return;
        // keep traversing to the left node
        inOrder(node->left);
        // set current nodes left to null, right to node, and current to the new right node
        current->left = NULL;
        current->right = node;
        current = node;
        // keep traversing to the right
        inOrder(node->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        // make a new resulting root
        TreeNode *resultingRoot = new TreeNode(0);
        current = resultingRoot;
        // do an inorder traversal starting from root
        inOrder(root);
        return resultingRoot->right;
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
    TreeNode *root = new TreeNode(5, new TreeNode(3), new TreeNode(6));
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8, new TreeNode(7), new TreeNode(8));
    vector<int> result = preorderTraversal(root);
    cout << "Preorder traversal of the original tree is: ";
    printVec(result);
    Solution mySol;
    TreeNode *newRoot = mySol.increasingBST(root);
    result = preorderTraversal(newRoot);
    cout << "Preorder traversal of the modified tree is: ";
    printVec(result);
    return 0;
}