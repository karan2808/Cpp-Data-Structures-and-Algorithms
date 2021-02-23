#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        unordered_set<int> numSet;
        for (auto i = start; i < nums.size(); i++)
        {
            // check for duplicates
            if (res.empty() || res.back()[1] != nums[i])
            {
                // if target - nums[i] is found in the set, append it to the result
                if (numSet.find(target - nums[i]) != numSet.end())
                {
                    res.push_back({target - nums[i], nums[i]});
                }
            }
            numSet.insert(nums[i]);
        }
        return res;
    }

    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        // if end of the array is reached, or if smallest number * k exceeds target or if greatest number *k is less than target
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        {
            // not possible to sum to target
            return res;
        }
        // compute two sum
        if (k == 2)
        {
            return twoSum(nums, target, start);
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i == start || nums[i - 1] != nums[i])
            {
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), set.begin(), set.end());
                }
            }
        }
        return res;
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};

void printVecVec(vector<vector<int>> nums)
{
    for (vector<int> &n : nums)
    {
        for (int i : n)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution mySol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    cout << "The quadruplets in 1, 0, -1, 0, -2, 2 that sum to 0 are " << endl;
    printVecVec(mySol.fourSum(nums, target));
    return 0;
}