#include <iostream>
#include <vector>
using namespace std;

class Solve
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // get num rows and cols
        int rows = obstacleGrid.size();
        if (rows == 0)
            return 0;
        int cols = obstacleGrid[0].size();
        // make a dp matrix
        int dp[rows][cols];
        memset(dp, 0, sizeof(int) * rows * cols);
        // set num ways to go right to 1, break if an obstacle is encountered
        for (int i = 0; i < rows; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        // set num ways to go down all the way to 1, break if an obstacle is encountered
        for (int j = 0; j < cols; j++)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }
        // fill the dp array
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                // if an obstacle is encountered, set the ways to 0
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                {
                    // add the number of ways to come from above and left
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    Solve mySol;
    vector<vector<int>> obsGrid0 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obsGrid1 = {{0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
    vector<vector<int>> obsGrid2 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obsGrid3 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}, {0, 0, 0}};
    cout << "Num ways for obstacle grid 0: " << mySol.uniquePathsWithObstacles(obsGrid0) << endl;
    cout << "Num ways for obstacle grid 1: " << mySol.uniquePathsWithObstacles(obsGrid1) << endl;
    cout << "Num ways for obstacle grid 2: " << mySol.uniquePathsWithObstacles(obsGrid2) << endl;
    cout << "Num ways for obstacle grid 3: " << mySol.uniquePathsWithObstacles(obsGrid3) << endl;
    return 0;
}