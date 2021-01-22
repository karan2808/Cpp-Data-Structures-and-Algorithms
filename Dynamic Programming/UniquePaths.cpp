#include <iostream>

using namespace std;

class Solve {
    public:
    int uniquePaths(int m, int n) {
        // make a dp array
        int dp[m][n];
        // set all elements to 0
        memset(dp, 0, sizeof(int) * m * n);
        // you have only one way to go right and only one way to go down
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // number of ways to come from up + number of ways to come from right
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solve mysol;
    cout << "Number of ways for a 3 x 2 grid: " << mysol.uniquePaths(3, 2) << endl; 
    cout << "Number of ways for a 5 x 8 grid: " << mysol.uniquePaths(5, 8) << endl; 
    cout << "Number of ways for a 775 x 898 grid: " << mysol.uniquePaths(775, 898) << endl; 
    return 0;
}