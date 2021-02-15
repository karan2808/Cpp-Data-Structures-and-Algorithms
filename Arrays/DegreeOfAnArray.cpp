#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_map<int, int> count;
        int numsSz = nums.size();
        int degree = 0;
        int ans = numsSz;
        // for nums, update the left right and count
        for (int i = 0; i < numsSz; i++)
        {
            // left index, index where the number first appeared
            if (left.find(nums[i]) == left.end())
            {
                left[nums[i]] = i;
            }
            // index where the number last appeared
            right[nums[i]] = i;
            // increment count each time a number is seen
            count[nums[i]]++;
            // keep updating degree
            degree = max(degree, count[nums[i]]);
        }
        // get the sub arr of min length
        for (int num : nums)
        {
            if (degree == count[num])
            {
                ans = min(ans, right[num] - left[num] + 1);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1};
    Solution mySol;
    cout << "The smallest possible length of a contiguous sub array of nums that has the same degree as nums is " << mySol.findShortestSubArray(nums) << endl;
    return 0;
}