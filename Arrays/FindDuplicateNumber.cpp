#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // use the two pointer approach, fast and slow pointer
        int tortoise = nums[0];
        int hare = nums[0];
        // step slow pointer by one, and fast by two, until they are equal
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        // start the slow pointer from the beginning and step it until its equal to hare
        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        // return the slow pointer value
        return tortoise;
    }
};

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    Solution mySol;
    cout << "The duplicate num in nums 3, 1, 3, 4, 2 is " << (mySol.findDuplicate(nums)) << endl;
    return 0;
}