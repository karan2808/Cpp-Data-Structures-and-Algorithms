#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // sort the nums in  ascending order
        sort(begin(nums), end(nums));
        // compute and return k sum
        return kSum(nums, target, 0, 4);
    }
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        // if we exhaust all the nums
        // if k times the smallest number is greater than target, we cannot make target
        // if target is greater than nums.back * k, the sum wont be large enough to compute target
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k) {
            return res;
        }

        // if two numbers are left compute the two sum
        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            // if the nums are repeated
            if (i == start || nums[i - 1] != nums[i]) {
                // generate combinations as sets
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    // append num to result
                    res.push_back({nums[i]});
                    // insert the acquired set to result
                    res.back().insert(res.back().end(), set.begin(), set.end());
                }
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        unordered_set<int> s;
        for (auto i = start; i < nums.size(); ++i)
        {
            // check for duplicates
            if (res.empty() || res.back()[1] != nums[i]) {
                // if the diff is found in set 
                if (s.find(target - nums[i]) != s.end()) {
                    // append the two numbers to set
                    res.push_back({target - nums[i], nums[i]});
                }
            }
            // insert the num to the set
            s.insert(nums[i]);
        }
        return res;
    }
};

void printVecVec(vector<vector<int>> VecVec)
{
    for (vector<int> Vec : VecVec)
    {
        for (int v : Vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution mySol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = mySol.fourSum(nums, target);
    printVecVec(result);
    return 0;
}