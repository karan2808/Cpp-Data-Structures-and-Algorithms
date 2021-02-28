#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isCyclic(vector<vector<char>> &grid, vector<vector<bool>> &vis, int curi, int curj, int lasti, int lastj, int target)
    {
        // check boundary conditions
        if (curi < 0 || curj < 0 || curi > grid.size() - 1 || curj > grid[0].size() - 1 || grid[curi][curj] != target)
        {
            return false;
        }
        // check if the node has been visited
        if (vis[curi][curj])
            return true;
        // mark visited
        vis[curi][curj] = true;
        // do not visit the last visited cell, two adjacent cells are not cycles
        if ((curi + 1 != lasti || curj != lastj) && isCyclic(grid, vis, curi + 1, curj, curi, curj, target))
            return true;
        if ((curi - 1 != lasti || curj != lastj) && isCyclic(grid, vis, curi - 1, curj, curi, curj, target))
            return true;
        if ((curi != lasti || curj + 1 != lastj) && isCyclic(grid, vis, curi, curj + 1, curi, curj, target))
            return true;
        if ((curi != lasti || curj - 1 != lastj) && isCyclic(grid, vis, curi, curj - 1, curi, curj, target))
            return true;
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!vis[i][j] && isCyclic(grid, vis, i, j, -1, -1, grid[i][j]))
                    return true;
            }
        }
        return false;
    }
};

void printGrid(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> grid = {{'c', 'c', 'c', 'a'},
                                 {'c', 'd', 'c', 'c'},
                                 {'c', 'c', 'e', 'c'},
                                 {'f', 'c', 'c', 'c'}};
    Solution mySol;
    string containsCycle = mySol.containsCycle(grid) ? "Yes" : "No";
    cout << "Does the given grid: " << endl;
    printGrid(grid);
    cout << containsCycle << endl;
}