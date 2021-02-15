#include <iostream>
#include <vector>
// nums: 4, 5, 6, 7, 0, 1, 2
// target - 0
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid = 0, l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            // if low is less than nums mid
            if (nums[l] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[l])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            } // if high is greater than nums mid
            else if (nums[h] >= nums[mid])
            {
                if (target <= nums[h] && target >= nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

void printVec(vector<int> &nums)
{
    for (int v : nums)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    Solution mySol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "The position of 0 in the rotated array: ";
    printVec(nums);
    cout << mySol.search(nums, target) << endl;
    return 0;
}