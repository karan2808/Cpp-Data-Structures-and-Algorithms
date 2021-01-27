#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(int nums[], int numNumbers)
    {
        bool has_1 = false;
        // check if the array has 1
        for (int i = 0; i < numNumbers; i++)
        {
            if (nums[i] == 1)
                has_1 = true;
            // if the number is negative or out of bounds, set it to 1
            if (nums[i] <= 0 || nums[i] > numNumbers)
                nums[i] = 1;
        }
        // if the array does not have 1 return 1
        if (!has_1)
            return 1;
        // go over the array and set the positive numbers to negative
        for (int i = 0; i < numNumbers; i++)
        {
            // convert num to an index
            int idx = abs(nums[i]) - 1;
            // if num > 0, set it to a negative number
            if (nums[idx] > 0)
            {
                nums[idx] = -nums[idx];
            }
        }
        // get the first positive, its index will be the missing number
        for (int i = 0; i < numNumbers; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return numNumbers + 1;
    }
};

int main()
{
    Solution mySol;
    int nums[7] = {-1, 0, 1, 3, 4, 8, 666};
    cout << "The smallest positive number for the array -1, 0, 1, 3, 4, 8, 666 " << mySol.firstMissingPositive(nums, 7) << endl;
    return 0;
}