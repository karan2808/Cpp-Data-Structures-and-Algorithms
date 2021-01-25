#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int maxArea;
    int dfs(vector<vector<int>>& grid, int row, int col, int Rows, int Cols) {
        // if at the boundary return 0
        if (row < 0 || row >= Rows || col < 0 || col >= Cols || grid[row][col] == 0) {
            return 0;
        }
        int current_sum = 1;
        // set the grid val to 0 so its not visited again
        grid[row][col] = 0;
        // do a dfs on current lands neighbors
        current_sum += dfs(grid, row + 1, col, Rows, Cols);
        current_sum += dfs(grid, row - 1, col, Rows, Cols);
        current_sum += dfs(grid, row, col + 1, Rows, Cols);
        current_sum += dfs(grid, row, col - 1, Rows, Cols);
        return current_sum;
    }
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Rows = grid.size();
        if (!Rows) return 0;
        int Cols = grid[0].size();
        maxArea = 0;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                // if we encounter land
                if (grid[i][j] == 1)
                    // do a dfs on current cell and keep updating max area encountered
                    maxArea = max(maxArea, dfs(grid, i, j, Rows, Cols));
            }
        }
        return maxArea;
    }
};

void printVecVec(vector<vector<int>> VecVec) {
    for (vector<int> Vec: VecVec) {
        for (int element: Vec) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution mySol;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    printVecVec(grid);
    cout << "The max area of the island is " << mySol.maxAreaOfIsland(grid) << endl;
    return 0;
}