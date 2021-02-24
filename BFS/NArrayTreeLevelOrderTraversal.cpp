#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a node
class Node
{
public:
    int val;
    vector<Node *> children;

    // constructors of nodes
    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        // make a queue
        queue<Node *> Queue;
        // push the root node
        Queue.push(root);
        // traverse level by level
        while (!Queue.empty())
        {
            int sz = Queue.size();
            // store the current level
            vector<int> currentLevel;
            // go through each node in the queue
            for (int i = 0; i < sz; i++)
            {
                // get the current node
                Node *current = Queue.front();
                currentLevel.push_back(current->val);
                Queue.pop();
                // go through the children of the current node and push them to the queue
                if (current->children.size())
                {
                    for (Node *child : current->children)
                    {
                        Queue.push(child);
                    }
                }
            }
            // push back current level to result
            result.push_back(currentLevel);
        }
        return result;
    }
};

void printVec(vector<vector<int>> result) {
    for (vector<int> res: result) {
        for (int v: res) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution mySol;
    Node* Root = new Node(5);
    Root->children.push_back(new Node(10));
    Root->children.push_back(new Node(15));
    Root->children.push_back(new Node(20));
    Root->children.push_back(new Node(50));
    Root->children[0]->children.push_back(new Node(6));
    Root->children[0]->children.push_back(new Node(8));
    Root->children[0]->children.push_back(new Node(12));
    Root->children[0]->children.push_back(new Node(14));
    Root->children[1]->children.push_back(new Node(19));
    Root->children[0]->children.push_back(new Node(14));
    Root->children[0]->children[0]->children.push_back(new Node(18));
    Root->children[1]->children.push_back(new Node(24));
    cout << "The level order traversal of the tree is ";
    vector<vector<int>>result = mySol.levelOrder(Root);
    printVec(result);
    return 0;
}