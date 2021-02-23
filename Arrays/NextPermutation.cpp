#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    // swap nums, O(1), O(1)
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    // reverse nums O(N), O(1)
    void reverse(vector<int> &nums, int start)
    {
        int i = start, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        // find the first index where the nums are not in descending order
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            // find the first number for which nums[i] >= to that number
            // 1, 2, 3, 6, 6, 4, 5
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
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
    vector<int> nums = {1, 2, 3, 6, 5, 4, 3, 2, 1};
    cout << "The next permutation for ";
    printVec(nums);
    mySol.nextPermutation(nums);
    printVec(nums);
}