#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
using namespace std;

class Solution
{
    // the dp array holds the win status
    int *dp;

public:
    Solution()
    {
        dp = new int[4200000];
    }
    // check if number has already been used
    bool checkIfUsed(int track, int pos)
    {
        return ((track >> pos) & 1) == 1;
    }

    // returns who won
    int game(int left, int right, int desiredTotal, int track, bool player)
    {
        // if desired total goes 0 or negative previous player won
        if (desiredTotal <= 0) return dp[track] = player ? -1 : 1;

        // if dp value available, return it
        if (dp[track] != 0)
            return dp[track];

        int result;
        // player 1 ries to maximize
        if (player)
        {
            result = INT_MIN;
            for (int i = left; i <= right; i++)
            {
                // check if the number has been used
                if (!checkIfUsed(track, i))
                {
                    // subtract the taken number from total, mark the taken number and flip the player
                    result = max(result, game(left, right, desiredTotal - i, track | (1 << i), !player));

                    // if player wins, return result
                    if (result == 1)
                        return dp[track] = 1;
                }
            }
        }
        else
        {
            result = INT_MAX;
            for (int i = left; i <= right; i++)
            {
                if (!checkIfUsed(track, i))
                {
                    // player2 minimizes
                    result = min(result, game(left, right, desiredTotal - i, track | (1 << i), !player));

                    // return if player won
                    if (result == -1)
                        return dp[track] = -1;
                }
            }
        }

        dp[track] = result;
        return result;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        memset(dp, 0, sizeof(int) * 4200000);
        // desiredTotal == 0 then player1 wins
        if (desiredTotal == 0)
            return true;

        // sum of all number in range 1 to max choosable number
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        // if sum < desiredTotal then there is no way to win and so return false
        if (sum < desiredTotal)
            return false;

        int track = 0;

        // player1 wins using an optimal move
        return game(1, maxChoosableInteger, desiredTotal, track, true) == 1;
    }
};

int main()
{
    Solution mySol;
    string s = mySol.canIWin(10, 11) ? "yes" : "no";
    cout << "Can I win if max choosable integer is 10 and sum is 11: " << s << endl;
    s = mySol.canIWin(16, 11) ? "yes" : "no";
    cout << "Can I win if max choosable integer is 16 and sum is 11: " << s << endl;
    return 0;
}