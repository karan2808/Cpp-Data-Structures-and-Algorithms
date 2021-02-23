#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), diff = INT_MAX;
        // sort the numbers for convenience 
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // use the two pointer approach
            int j = i + 1, k = n - 1;
            while (j < k) {
                // get the current sum
                int sum = nums[i] + nums[j] + nums[k];
                // if the absolute diff is less than previous diff
                if (abs(target - sum) < abs(diff)) {
                    // update diff
                    diff = target - sum;
                }
                // if sum is less than target, add more to sum else subtract more from it
                if (sum < target) j++;
                else k--;
            }
        }
        // return closest
        return target - diff;
    }
};

int main() {
    Solution mySol;
    vector<int>nums = {-1, 2, 1, -4};
    cout << "The closest sum for nums 1, 2, 1, -4 and target 1 is " << mySol.threeSumClosest(nums, 1) << endl;
    return 0;
}