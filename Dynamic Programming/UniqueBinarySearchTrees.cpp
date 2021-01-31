#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    // # for bsts with 4 nodes,
    // # fix 1st node and make bsts with 3 nodes,
    // # fix 2nd node and make bsts with 2 nodes on right, on left, make bsts with one node
    // # similarly for 3rd node we make bsts with 2 nodes on left and one on right
    // # for 4th node we make bsts with 3 nodes on left
    // # i = 0, 1, 2, 3->
    // # bsts += dp[0] * dp[3] + dp[1] * dp[2] + dp[2] * dp[1] + dp[3] * dp[0]
    int findBSTS(vector<int> &dp, int current)
    {
        int ways = 0;
        for (int i = 0; i < current; i++)
        {
            ways += dp[i] * dp[current - i - 1];
        }
        return ways;
    }

public:
    int findUniqueBSTS(int n)
    {
        vector<int> dp(n + 1, 0);
        // # if n = 1, only 1 tree possible, if 2, only 2 trees possible
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = findBSTS(dp, i);
        }
        return dp[n];
    }
};

int main()
{
    Solution mySol;
    cout << "The number of unique bsts for n = 5 is " << mySol.findUniqueBSTS(5) << endl;
}