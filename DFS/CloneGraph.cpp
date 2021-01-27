#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition of a Graph Node
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int val)
    {
        this->val = val;
        neighbors = vector<Node *>();
    }
    Node(int val, vector<Node *> neighbors)
    {
        this->val = val;
        this->neighbors = neighbors;
    }
};

class Solution
{
    unordered_map<Node *, Node *> clones_dfs;

public:
    Node *dfs(Node *node)
    {
        if (!node)
            return node;
        // if the node is not present in the map
        if (clones_dfs.find(node) == clones_dfs.end())
        {
            // put the clone in the map
            clones_dfs[node] = new Node(node->val);
            // for nodes neighbors
            for (Node *child : node->neighbors)
            {
                // add clones of neighbors
                clones_dfs[node]->neighbors.push_back(dfs(child));
            }
        }
        return clones_dfs[node];
    }
    // clone graph using dfs
    Node *cloneGraphDFS(Node *node)
    {
        if (!node)
            return node;
        return dfs(node);
    }
};

int main()
{
    Node *head = new Node(10);
    head->neighbors.push_back(new Node(12));
    head->neighbors.push_back(new Node(14));
    head->neighbors.push_back(new Node(16));
    head->neighbors[0] = head->neighbors[1];
    head->neighbors[1] = head->neighbors[2];
    Solution mySol;
    cout << head << endl;
    cout << mySol.cloneGraphDFS(head) << endl;
    return 0;
}