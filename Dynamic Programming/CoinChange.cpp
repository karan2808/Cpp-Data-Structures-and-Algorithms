#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // fill the dp array with amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // 0 coins for 0 amount
        dp[0] = 0;
        // fill the dp array
        for (int i = 0; i < amount + 1; i++)
        {
            for (int coin : coins)
            {
                // if the denomination is less than the current value
                if (coin <= i)
                {
                    // the number of coins will be the minimum of the current number of coins and
                    // the number of coins when we fix the current coin and add the number of ways for amount i - coin
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        // if dp[amount] == amount + 1, no denominations possible
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main()
{
    Solution mySol;
    vector<int> coins = {1, 2, 3, 4, 5};
    int amount = 12;
    cout << "Fewest number of coins needed to make amount 12 given demoniations {1, 2, 3, 4, 5} is " << mySol.coinChange(coins, amount) << endl;
    return 0;
}