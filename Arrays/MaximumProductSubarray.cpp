#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int maxProduct(vector<int> &nums) {
        int sz = nums.size();
        int currentMax = nums[0];
        int currentMin = nums[0];
        int finalMax = nums[0];
        int temp = 0;
        for (int i = 1; i < sz; i++) {
            // keep current max in temp
            temp = currentMax;
            // update current max and current min, if current min is highly negative, and current num is negative, the prod will be +ve and may be greter than current max and num
            // if the current max and min are 0, and num is +ve, max will be current num
            currentMax = max({currentMax * nums[i], currentMin * nums[i], nums[i]});
            currentMin = min({temp * nums[i], currentMin * nums[i], nums[i]});
            if (finalMax < currentMax) {
                finalMax = currentMax;
            }
        }
        return finalMax;
    }
};

int main() {
    Solution mySol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "The max product in nums 2, 3, -2, 4 is " << mySol.maxProduct(nums) << endl;
    return 0;
}