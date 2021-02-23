#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int extremeInsertionIdx(vector<int> &nums, int target, bool left)
    {
        int low = 0;
        int high = nums.size();
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target || (left && target == nums[mid]))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftIdx = extremeInsertionIdx(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target)
        {
            return {-1, -1};
        }
        return {leftIdx, extremeInsertionIdx(nums, target, false) - 1};
    }
};

void printVec(vector<int> nums)
{
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    Solution mySol;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    cout << "For the array " << endl;
    printVec(arr);
    cout << "The range for the target 8 is " << endl;
    printVec(mySol.searchRange(arr, target));
    return 0;
}