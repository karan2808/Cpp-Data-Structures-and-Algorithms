#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int findWays(vector<int> &nums, vector<vector<int>> &dp, int S, int idx, int sum)
    {
        // if all nums have been exhausted, check if sum has been reached
        if (idx == nums.size())
        {
            return S == sum ? 1 : 0;
        }
        // if the dp value is already present, return it
        if (dp[idx][sum + 1000] != INT_MIN)
        {
            return dp[idx][sum + 1000];
        }
        else
        {
            // find total ways if a number from nums is added as well as subtracted
            int ans = findWays(nums, dp, S, idx + 1, sum - nums[idx]) +
                      findWays(nums, dp, S, idx + 1, sum + nums[idx]);
            // store the result in dp
            dp[idx][sum + 1000] = ans;
            return ans;
        }
    }

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, INT_MIN));
        return findWays(nums, dp, S, 0, 0);
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int sum = 3;
    Solution mySol;
    cout << "The number of ways to assign symbols to make the sum of nums equal to 3 is " << mySol.findTargetSumWays(nums, sum);
    cout << endl;
    return 0;
}