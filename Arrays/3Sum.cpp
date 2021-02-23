#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // if less than 3 nums, return 
        if (n < 3) return {};
        vector<vector<int>> result;
        // sort the nums O(n log n)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                // use two pointers 
                int j  = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k]; 
                    if (sum == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        // check for duplicates again
                        while (j < k && nums[j] == nums[j + 1]) j++;
                        while (j < k && nums[k] == nums[k - 1]) k--;
                    }
                    // if sum is positive, decrement k else increment j (add more)
                    if (sum > 0) k--;
                    else j++;
                }
            }
        }
        return result;
    }
};

void printVec(vector<int> nums) {
    for (int &n: nums) {
        cout << n << " ";
    }
    cout << endl;
}

void printVecVec(vector<vector<int>> nums) {
    for (vector<int> &v: nums) {
        for (int &n: v) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution mySol;
    vector<int> nums = {1, 2, 3, 4, 5, 65, 3, 2, 1, 0, -4, 1, 5, 6};
    cout << "For the nums ";
    printVec(nums);
    cout << "the nums that sum to 0 are ";
    printVecVec(mySol.threeSum(nums));
    return 0;
}