#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int coinsSz = coins.size();
        // make a dp matrix
        int dp[coinsSz + 1][amount + 1];
        // for 0 amount only 1 way, exclude all coins
        for (int i = 0; i <= coinsSz; i++)
        {
            dp[i][0] = 1;
        }
        // for 0 coins, no way
        for (int i = 1; i <= amount; i++)
        {
            dp[0][i] = 0;
        }
        // fill the dp matrix
        for (int i = 1; i <= coinsSz; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                // if the current amount is greater than denomination
                if (j >= coins[i - 1])
                {
                    // ways without coin to make current amount + ways to make current amount with coin
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                // exclude the coin
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coinsSz][amount];
    }

    int change2(int amount, vector<int> &coins)
    {
        int dp[amount + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution MySol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "The number of combinations to make 5 from coins 1, 2, 5 is " << MySol.change(5, coins) << endl;
    return 0;
}