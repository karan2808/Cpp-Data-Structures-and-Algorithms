#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (nums[mid] > target)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution mySol;
    cout << "The position of target 5 in nums 1, 3, 5, 6 " << endl << mySol.searchInsert(nums, target) << endl;
    return 0;
}