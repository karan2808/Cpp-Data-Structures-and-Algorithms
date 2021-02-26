#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        // for count == 0, index is -1
        map[0] = -1;
        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if current number is 1, add 1 to count else decrement from count
            count = count + (nums[i] == 1 ? 1 : -1);
            // if count already exists in map, find number of elements starting from the index pointed by it
            if (map.find(count) != map.end()) {
                maxLen = max(maxLen, i - map[count]);
            } else {
                // store the index of the count
                map[count] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1};
    Solution MySol;
    cout << "The maximum length of a contiguous sub array with equal number of 0 and 1 is " << MySol.findMaxLength(nums) << endl;
    return 0;
}