#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    // up down left right directions
    int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &cache, int row, int col, int Rows, int Cols)
    {
        // if cache value exisits, return it
        if (cache[row][col] > 0)
            return cache[row][col];

        int maxVal = 0, x, y;
        // go in all directions
        for (auto direction : DIRECTIONS)
        {
            // make a direction vector x, y
            x = row + direction[0];
            y = col + direction[1];
            // check boundary conditions, and if path is increasing
            if (x > 0 && y > 0 && x < Rows && y < Cols && matrix[x][y] > matrix[row][col])
            {
                maxVal = max(maxVal, dfs(matrix, cache, x, y, Rows, Cols));
            }
        }
        // increment maxVal and return it
        cache[row][col] = maxVal + 1;
        return cache[row][col];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int Rows = matrix.size();
        if (Rows == 0)
            return 0;
        int Cols = matrix[0].size();
        // cache the values
        vector<vector<int>> cache(Rows, vector<int>(Cols, 0));
        int maxVal = 0;
        // go through all the elements in the matrix
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                // update max values
                maxVal = max(maxVal, dfs(matrix, cache, i, j, Rows, Cols));
            }
        }
        return maxVal;
    }
};

void printVecVec(vector<vector<int>> VecVec)
{
    for (vector<int> Vec : VecVec)
    {
        for (int element : Vec)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}, {1, 1, 1}};
    Solution mySol;
    cout << "The longest incresing path length in the grid: ";
    printVecVec(matrix);
    cout << "is " << mySol.longestIncreasingPath(matrix) << endl;
    return 0;
}