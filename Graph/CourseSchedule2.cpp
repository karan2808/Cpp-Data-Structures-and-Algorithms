#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &adj, int v, vector<bool> &visited, stack<int> &mystack)
    {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (!visited[adj[v][i]])
                dfs(adj, adj[v][i], visited, mystack);
        }
        mystack.push(v);
    }

    bool is_cycle_util(vector<vector<int>> &adj, vector<int> &visited, int v)
    {
        // if the node is in gray set there exists a cycle, since that node is already being explored
        if (visited[v] == 1)
            return true;
        // if the node is in black set, there is no cycle, the exploration is over
        if (visited[v] == 2)
            return false;

        // put the node in gray set
        visited[v] = 1;

        // visit the nodes neighbors, if ther is a cycle, the node will be encountered again
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (is_cycle_util(adj, visited, adj[v][i]))
                return true;
        }

        // if there is no cycle, put the node into black set
        visited[v] = 2;
        return false;
    }

    bool isCycle(vector<vector<int>> &adj, int V)
    {
        // use the white gray and black set technique to find cycle
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            // if the node is in white set, run the cycle util
            if (!visited[i])
            {
                if (is_cycle_util(adj, visited, i))
                    return true;
            }
        }

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // store the courses in order
        vector<int> courses;
        // make an adjacency list
        vector<vector<int>> adj(numCourses);

        int size_prereq = prerequisites.size();

        // fill the adjacency list
        for (int i = 0; i < size_prereq; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // if there is a cycle, you cannot finish all the courses
        if (isCycle(adj, numCourses))
            return courses;

        // make a stack and put the nodes on it  [1, 0]  0->1->2. stack, 012 pop 0, 1, 2
        // nodes come out in reverse order
        stack<int> mystack;
        // make a visited array for dfs
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            // if a node is not visited, run dfs
            if (!visited[i])
            {
                dfs(adj, i, visited, mystack);
            }
        }

        // while the stack is not empty, push the stack top to courses
        while (!mystack.empty())
        {
            courses.push_back(mystack.top());
            mystack.pop();
        }

        return courses;
    }
};

void printVec(vector<int> vec)
{
    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> courses1 = {{1, 0}, {0, 1}};
    vector<vector<int>> courses2 = {{1, 0}, {2, 0}, {0, 1}, {3, 1}, {3, 2}};
    vector<vector<int>> courses3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> courses4 = {{1, 0}};
    Solution mysol;
    cout << "The order in which the courses {1, 0}, {0, 1} should be completed is ";
    printVec(mysol.findOrder(2, courses1));
    cout << "The order in which the courses {1, 0}, {2, 0}, {0, 1}, {3, 1}, {3, 2} should be completed is ";
    printVec(mysol.findOrder(4, courses2));
    cout << "The order in which the courses {1, 0}, {2, 0}, {3, 1}, {3, 2} should be completed is ";
    printVec(mysol.findOrder(4, courses3));
    cout << "The order in which the courses {1, 0} should be completed is ";
    printVec(mysol.findOrder(2, courses4));
    return 0;
}