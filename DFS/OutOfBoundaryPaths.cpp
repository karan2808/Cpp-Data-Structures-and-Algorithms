#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// brute force method, time complexity O(4^n), space complexity O(n)
class BruteForce
{
public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        if (i == m || j == n || i < 0 || j < 0)
            return 1;
        if (N == 0)
            return 0;
        return findPaths(m, n, N - 1, i - 1, j) +
               findPaths(m, n, N - 1, i + 1, j) +
               findPaths(m, n, N - 1, i, j - 1) +
               findPaths(m, n, N - 1, i, j + 1);
    }
};

class DynamicProgramming
{
public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[i][j] = 1;
        int count = 0;
        // for the given number of moves
        for (int moves = 1; moves <= N; moves++)
        {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            // fill the dp array
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // at boundaries, add the number of ways to count
                    // if a position can be reached in x moves, its neighbors can be reached in x + 2 moves
                    if (i == m - 1)
                        count = count + dp[i][j];
                    if (j == n - 1)
                        count = count + dp[i][j];
                    if (i == 0)
                        count = count + dp[i][j];
                    if (j == 0)
                        count = count + dp[i][j];
                    temp[i][j] = ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0));
                }
            }
            // equate dp to temp, we need to evaluate all counts for moves from 1 to N
            dp = temp;
        }
        return count;
    }
};

int main()
{
    BruteForce sol1;
    auto start = high_resolution_clock::now();
    cout << "The number of paths with 2 rows, 2 cols, max 2 moves, current row 0 and current col 0 is " << sol1.findPaths(2, 2, 2, 0, 0) << endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time in us: ";
    cout << duration.count() << endl;
    DynamicProgramming sol2;
    start = high_resolution_clock::now();
    cout << "The number of paths with 2 rows, 2 cols, max 2 moves, current row 0 and current col 0 is " << sol2.findPaths(2, 2, 2, 0, 0) << endl;
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Execution time in us: ";
    cout << duration.count() << endl;
    return 0;
}