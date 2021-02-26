#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> nums_map;
        int i = 0;
        // store the array index in map
        for (int &num : nums)
        {
            nums_map[num] = i++;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums_map.find(target - nums[j]) != nums_map.end())
            {
                if (nums_map[target - nums[j]] != j)
                {
                    return {nums_map[target - nums[j]], j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution mySol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = mySol.twoSum(nums, target);
    cout << "The indices of array 2, 7, 11, 15 for which the numbers add up to target are " << result[0] << " " << result[1] << endl;
    return 0;
}