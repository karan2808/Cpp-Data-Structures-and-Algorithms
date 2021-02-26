#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum = 0;
        // keep counts of sum
        unordered_map<int, int> countMap;
        countMap[0] = 1;
        for (int num : nums)
        {
            // compute a running sum
            sum += num;
            // if sum - k is present in count map, add the count of sum - k to running count
            if (countMap.find(sum - k) != countMap.end())
            {
                count += countMap[sum - k];
            }
            // update count of sum in count map
            countMap[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution mySol;
    vector<int> nums = {1, 2, 3, 3, 6, -3};
    int sum = 3;
    cout << "The total number of continuous sub arrays of 1, 2, 3, 3, 6, -3 whose sum equals 3 is " << mySol.subarraySum(nums, sum) << endl;
    return 0;
}