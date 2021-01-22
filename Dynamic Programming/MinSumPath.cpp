#include <iostream>
#include <vector>

using namespace std;

class Solve
{
public:
    int minPath(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();
        // find sum considering we go only right
        for (int i = 1; i < cols; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        // find sum considering we go only down
        for (int j = 1; j < rows; j++)
        {
            grid[j][0] += grid[j - 1][0];
        }
        // traverse through the whole grid
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                // get min sum, two options: either come from left or up
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[rows - 1][cols - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solve mySol;
    cout << "Sum along the min sum path for the grid {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}} is " << mySol.minPath(grid) << endl;
    return 0;
}