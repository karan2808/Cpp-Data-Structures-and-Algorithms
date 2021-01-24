#include <iostream>
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

class BSTIterator
{
    stack<TreeNode *> stk;
    // go all the way left, and push the encountered nodes onto stack
    void go_left(TreeNode *root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

public:
    // constructor
    BSTIterator(TreeNode *root)
    {
        go_left(root);
    }
    // get the next element
    int next()
    {
        // the top most element on the stack is the current node
        TreeNode *topMost = stk.top();
        stk.pop();
        // if current node has a right member, visit it and push it's left side on the stack
        if (topMost->right)
        {
            go_left(topMost->right);
        }
        return topMost->val;
    }
    // check if there is a next node
    bool hasNext()
    {
        return stk.size() > 0;
    }
};

int main()
{
    TreeNode *root1 = new TreeNode(7, new TreeNode(3), new TreeNode(15));
    root1->left->left = new TreeNode(-1, new TreeNode(-2), new TreeNode(0));
    root1->left->right = new TreeNode(8);
    TreeNode *root2 = new TreeNode(9, new TreeNode(-1), new TreeNode(11));
    root2->right->left = new TreeNode(9, new TreeNode(6), new TreeNode(12));
    root2->left->right = new TreeNode(0);
    BSTIterator bstIter1(root1);
    cout << "The next element in tree 1 is " << bstIter1.next() << endl;
    cout << "The next element in tree 1 is " << bstIter1.next() << endl;
    cout << "The next element in tree 1 is " << bstIter1.next() << endl;
    cout << "The next element in tree 1 is " << bstIter1.next() << endl;
    BSTIterator bstIter2(root2);
    cout << "The next element in tree 2 is " << bstIter2.next() << endl;
    cout << "The next element in tree 2 is " << bstIter2.next() << endl;
    cout << "The next element in tree 2 is " << bstIter2.next() << endl;
    cout << "The next element in tree 2 is " << bstIter2.next() << endl;
    cout << "The next element in tree 2 is " << bstIter2.next() << endl;
    string bstIter2HasNext = bstIter2.hasNext() ? "Yes" : "No";
    cout << "Does bst iter 2 have a next element? " << bstIter2HasNext << endl;
    return 0;
}