// credit: geeks for geeks
#include <iostream>
#include <vector>

using namespace std;
#define COUNT 5

// Binary Tree Node
class Node
{
public:
    int data;
    Node *left, *right;
    // Initialize new nodes
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to print binary tree in 2D
// Do a reverse inorder traversal
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    // Increase distance between levels
    space += COUNT;
    // process right child
    print2DUtil(root->right, space);
    // print current node after space
    cout << endl;
    for (int i = COUNT; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << "\n";
    // process left child
    print2DUtil(root->left, space);
}

// Wrapper over print 2D util
void print2D(Node *root)
{
    // pass initial space count 0
    print2DUtil(root, 0);
}

// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    print2D(root);

    return 0;
}