#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    bool is_cycle_util(vector<vector<int>> &adj, vector<int> &visited, int v)
    {
        // if in gray set, there is a cycle because the node is being explored
        if (visited[v] == 1)
            return true;
        // if in black set, no cycle found, since we are done exploring the node
        if (visited[v] == 2)
            return false;
        // put the current node in gray set
        visited[v] = 1;
        // check its neighbors
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (is_cycle_util(adj, visited, adj[v][i]))
                return true;
        }
        // put the node in black set
        visited[v] = 2;
        return false;
    }

    // use the white gray and black sets to check for cycles
    bool isCycle(vector<vector<int>> &adj, int V)
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            // if in white set, explore it
            if (!visited[i])
            {
                // if a cycle is found return true
                if (is_cycle_util(adj, visited, i))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // can you finish all courses??
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // make an adjacency matrix
        vector<vector<int>> adj(numCourses);
        // get the size of prereqs
        int prereq_sz = prerequisites.size();
        // make the graph
        for (int i = 0; i < prereq_sz; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // check if there is a cycle in the graph, if yes, you cannot do all the courses
        if (isCycle(adj, numCourses))
            return false;
        return true;
    }
};

int main()
{
    Solution mySol;
    vector<vector<int>> courses1 = {{1, 0}, {2, 0}, {3, 2}, {3, 1}};
    vector<vector<int>> courses2 = {{1, 0}, {2, 0}, {0, 1}, {3, 2}};
    string s1 = mySol.canFinish(4, courses1) ? "Yes" : "No";
    string s2 = mySol.canFinish(4, courses2) ? "Yes" : "No";
    cout << "Can you finish the courses: {{1, 0}, {2, 0}, {3, 2}, {3, 1}} " << s1 << endl;
    cout << "Can you finish the courses: {{1, 0}, {2, 0}, {0, 1}, {3, 2}} " << s2 << endl;
}