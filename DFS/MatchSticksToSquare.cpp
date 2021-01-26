#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<int> nums;
    vector<int> sums;
    int possibleSquareSide;

public:
    Solution()
    {
        sums.resize(4, 0);
    }
    // depth first search function
    bool dfs(int idx)
    {
        // if we exhaust all the nums, check if all sides are equal
        if (idx == nums.size())
        {
            return sums[0] == sums[1] &&
                   sums[1] == sums[2] &&
                   sums[2] == sums[3];
        }
        // get current matchstick
        int element = nums[idx];
        // add it to each of the 4 sides, if its possible
        for (int i = 0; i < 4; i++)
        {
            // dfs + back tracking, add the element, check if the next element satisfies the condition, backtrack
            if (sums[i] + element <= possibleSquareSide)
            {
                sums[i] += element;
                if (dfs(idx + 1))
                {
                    return true;
                }
                sums[i] -= element;
            }
        }
        return false;
    }

    bool makeSquare(vector<int> &nums)
    {
        // if empty
        if (nums.size() == 0)
            return false;
        // find the perimeter of the square
        int sz = nums.size();
        int perimeter = 0;
        for (int i = 0; i < sz; i++)
        {
            perimeter += nums[i];
        }
        // set the max possible square side to perimeter / 4
        possibleSquareSide = perimeter / 4;
        // if you cannot make a square
        if (possibleSquareSide * 4 != perimeter)
            return false;
        // sort the nums
        sort(nums.begin(), nums.end());
        this->nums = nums;
        // return the dfs boolean
        return dfs(0);
    }
};

int main()
{
    Solution mySol;
    vector<int> nums1 = {1, 1, 2, 2, 2};
    vector<int> nums2 = {1, 2, 1, 2, 1, 2};
    string s1 = mySol.makeSquare(nums1) ? "Yes" : "No";
    string s2 = mySol.makeSquare(nums2) ? "Yes" : "No";
    cout << "Can the numbers 1, 1, 2, 2, 2 make a square? " << s1 << endl;
    cout << "Can the numbers 1, 2, 1, 2, 1, 2 make a square? " << s2 << endl;
    return 0;
}