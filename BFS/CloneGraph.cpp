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
    unordered_map<Node *, Node *> clones_bfs;

public:
    Node *cloneGraphBFS(Node *node)
    {
        if (!node)
            return node;
        // make a new head
        Node *currentClone = new Node(node->val);
        // update hashmap
        clones_bfs[node] = currentClone;
        // make a queue for bfs
        queue<Node *> nodesQ;
        nodesQ.push(node);

        // while queue is not empty
        while (!nodesQ.empty())
        {
            // get the current node
            Node *currentNode = nodesQ.front();
            nodesQ.pop();
            // for nodes in neighbors
            for (Node *currentNeighbor : currentNode->neighbors)
            {
                // if current neighbor not found in clones list
                if (clones_bfs.find(currentNeighbor) == clones_bfs.end())
                {
                    // make a new node for each one of the neighbors and push it to the queue
                    clones_bfs[currentNeighbor] = new Node(currentNeighbor->val);
                    nodesQ.push(currentNeighbor);
                }
                // append the neighbor clone to current node
                clones_bfs[currentNode]->neighbors.push_back(clones_bfs[currentNeighbor]);
            }
        }
        // return cloned head
        return currentClone;
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
    cout << mySol.cloneGraphBFS(head) << endl;
    return 0;
}