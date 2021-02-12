#include <iostream>
using namespace std;
/** 
 * say we have 4 nodes
 * for 1 node and 0 nodes, can have only 1 way to make a bst
 * for 2 nodes can have 2 ways
 * for each node num ways = numways to left + num ways to right
 * 1, 2, 3, 4
 *    |   
 * bsts[n] = sum(bsts[0->n - 1] * bsts[n -1 -> 0])
 */

class Solution {
    public:
    int getCount(int dp[], int curr) {
        int total = 0;
        for (int i = 0; i < curr; i++) {
            total += dp[i] * dp[curr - 1 - i];
        }
        return total;
    }
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int *dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = getCount(dp, i);
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    cout << "The number of unique binary search trees that can be constructed using 5 nodes are " << sol.numTrees(5) << endl;
    cout << "The number of unique binary search trees that can be constructed using 3 nodes are " << sol.numTrees(3) << endl;
    return 0;
}