#include <iostream>
#include <vector>

using namespace std;

class Profit {
    // recursively  find maximum profit
    int findMax(vector<int>& prices, int curr, int n, int dp[]) {
        // no more transactions
        if (curr >= n) return 0;
        // if dp value present, return it
        if (dp[curr] != -1) return dp[curr];
        int maxVal = 0;
        for (int i = curr + 1; i < n; i++) {
            // if you find a good day to sell
            if (prices[curr] < prices[i]) {
                // on ith day you make a profit, you sell on curr day, you wait for cool down to end and buy again
                maxVal = max(maxVal, prices[i] - prices[curr] + findMax(prices, i + 2, n, dp));
            }
        }
        // you dont buy on current day
        maxVal = max(maxVal, findMax(prices, curr + 1, n, dp));
        dp[curr] = maxVal;
        return maxVal;
    }
    public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        // return if size doesn't make sense
        if (sz <= 1) return 0;
        // make a dp array and initialize to -1
        int *dp = new int[sz + 1];
        memset(dp, -1, sizeof(int) * (sz + 1));
        return findMax(prices, 0, sz, dp);
    }
};

int main() {
    Profit myProfit;
    vector<int> prices = {1,2,3,0,2};
    cout << "The max profit for prices 1, 2, 3, 0, 2 is: " << myProfit.maxProfit(prices) << endl; 
    return 0;
}