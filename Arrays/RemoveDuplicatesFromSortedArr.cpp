#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < sz; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

void printVec(vector<int>& nums, int sz) {
    for (int n: nums) {
        if (sz == 0) break;
        cout << n << " ";
        sz--;
    }
    cout << endl;
}

int main() {
    Solution mySol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "After removing duplicates from ";
    printVec(nums, nums.size());
    cout << "The resulting array is ";
    int sz = mySol.removeDuplicates(nums);
    printVec(nums, sz);
    return 0;
}