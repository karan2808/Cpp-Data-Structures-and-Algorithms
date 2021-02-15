#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1);
        dp[0] = 0;
        // count the number of ones
        for (int i = 1; i <= num; i++)
        {
            dp[i] = dp[i / 2] + i % 2;
        }
        return dp;
    }
};

void printVec(vector<int> result)
{
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Solution mySol;
    cout << "The number of ones for each number from 0 to 8 is ";
    printVec(mySol.countBits(8));
    return 0;
}