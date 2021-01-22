#include <iostream>
#include <vector>

using namespace std;

class Solve {
    public:
    int maxSubArraySum(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        // set a local maximum and a global maximum
        int currMax = nums[0];
        int globalMax = currMax;

        // iterate through nums
        for (int i = 1; i < sz; i++) {
            // if the num decreases the local max below its own value, reset it
            currMax = max(currMax + nums[i], nums[i]);
            // keep a track of the global maximum
            globalMax = max(globalMax, currMax);
        }
        return globalMax;
    }
};

int main() {
    Solve mySol;
    vector<int> nums = {1, -1, 2, -3, 4, 2 -1, -5, 6, 9, -100, 4, -2};
    int maxSum = mySol.maxSubArraySum(nums);
    cout << "The maximum sum of subarray is " << maxSum << endl;
    return 0;
}