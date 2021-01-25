#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set Union Data Structure
class DSU
{
public:
    // parent arr
    vector<int> parent;

    // constructor, set parent to self
    DSU(int size)
    {
        parent.assign(size + 1, 0);
        for (int i = 0; i <= size; i++)
        {
            parent[i] = i;
        }
    }

    // find the parent of x
    int find(int x)
    {
        if (parent[x] != x)
        {
            // set to main parent
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // merge, set parent of x to parent of y
    void merge(int x, int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);
        parent[parent_x] = parent[parent_y];
    }
};

class Solution
{
public:
    vector<int> findRedundantConnections(vector<vector<int>> &edges)
    {
        int size = edges.size();
        vector<int> parent(size + 1, 0);
        vector<int> ans1;
        vector<int> ans2;
        for (auto &x : edges)
        {
            if (parent[x[1]] > 0)
            {
                // save the parent and current vertex in ans 1
                ans1.push_back(parent[x[1]]);
                ans1.push_back(x[1]);
                // save the edge in ans 2
                ans2 = x;
                x[0] = -1;
                x[1] = -1;
            }
            else
            {
                parent[x[1]] = x[0];
            }
        }
        DSU *dsu = new DSU(size);
        for (auto &x : edges)
        {
            if (x[0] < 0 || x[1] < 0)
                continue;
            // find parents of the two vertices, if they are equal, there is a cycle
            if (dsu->find(x[0]) == dsu->find(x[1]))
            {
                // if there is no saved edge, return current edge
                if (ans2.empty())
                    return x;
                // else return the saved vertex and its parent
                else
                    return ans1;
            }
            // merge the disjoint sets
            dsu->merge(x[0], x[1]);
        }
        // return saved edge
        return ans2;
    }
};

int main()
{
    Solution mySol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> edgeToRemove = mySol.findRedundantConnections(edges);
    cout << "For the graph {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}}, remove edge " << edgeToRemove[0] << " " << edgeToRemove[1] << endl;
    return 0;
}