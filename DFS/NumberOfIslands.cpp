#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int num_islands;
    int dfs(vector<vector<char>> &grid, int row, int col, int Rows, int Cols)
    {
        // check boundary conditions and if currently on water
        if (row < 0 || col < 0 || row >= Rows || col >= Cols || grid[row][col] == '0')
        {
            return 0;
        }
        // switch land to water
        grid[row][col] = '0';
        // visit neighbors and start a dfs until all connected regions of land are converted to water
        dfs(grid, row + 1, col, Rows, Cols);
        dfs(grid, row - 1, col, Rows, Cols);
        dfs(grid, row, col + 1, Rows, Cols);
        dfs(grid, row, col - 1, Rows, Cols);
        // finally return 1 indicating one island has been visited
        return 1;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        num_islands = 0;
        int Rows = grid.size();
        int Cols = grid[0].size();
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                // if currently on land, start a dfs
                if (grid[i][j] == '1')
                {
                    num_islands += dfs(grid, i, j, Rows, Cols);
                }
            }
        }
        return num_islands;
    }
};

void printVecVec(vector<vector<char>> VecVec)
{
    for (vector<char> Vec : VecVec)
    {
        for (char element : Vec)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution mySol;
    vector<vector<char>> grid = {
        {'1', '0', '1', '1', '1', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'1', '1', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1', '0'},
        {'1', '1', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '0', '0'},
    };
    cout << "Number of Islands on the given grid, " << endl;
    printVecVec(grid);
    cout << "is " << mySol.numIslands(grid) << endl;
    grid = {
        {'1', '0', '1', '0', '1', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1', '0'},
        {'0', '0', '1', '0', '1', '0'},
        {'1', '0', '0', '0', '1', '0'},
        {'1', '0', '1', '0', '0', '0'},
    };
    cout << "Number of Islands on the given grid, " << endl;
    printVecVec(grid);
    cout << "is " << mySol.numIslands(grid) << endl;
    return 0;
}