#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> memo;
    bool subsetSum(vector<int> &nums, int n, int pos, int sum) {
        // if we find a partition, return true
        if (sum == 0) return true;
        // if we exceede the number of elements in the array or if sum goes negative, we cannot parition, return false
        else if (pos >= n || sum < 0) return false;
        // if we have precomputed the value for current position and sum, return it
        if (memo[pos][sum] != -1) return memo[pos][sum];
        // we have two options, remove nums[pos] from current sum or to keep the sum as it is and look for other valid partitions 
        return memo[pos][sum] = subsetSum(nums, n, pos + 1, sum - nums[pos]) || subsetSum(nums, n, pos + 1, sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        // find the sum of nums
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        // if its not divisible by 2, we cannot partition the array
        if (sum % 2) return false;
        memo.clear();
        // make a memo matrix
        memo.resize(n + 1, vector<int> (sum/2 + 1, -1));
        // helper func
        return subsetSum(nums, n, 0, sum/2);
    }
};

void printVec(vector<int> nums) {
    for (int num: nums) {
        cout << num << " ";
    }
}

int main() {
    Solution mySol;
    vector<int> nums = {5, 1, 2, -1, 4, -5, 4};
    cout << "Can you partition ";
    printVec(nums);
    string ans = mySol.canPartition(nums) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}