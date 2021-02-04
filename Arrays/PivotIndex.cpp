# include <iostream>
# include <vector>

using namespace std;

class Solution{
    public:
    int findPivot(vector<int> nums) {
        // find the total sum of nums
        int total = 0;
        for (int x: nums) {
            total += x;
        }

        // keep a track of left sum
        int leftsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftsum == total - leftsum - nums[i]) {
                return i;
            }
            leftsum += nums[i];
        }

        return -1;
    }
};

void printVec(vector<int> values)
{
    for (int val : values)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution mySol;
    vector<int> nums = {1, 2, -1, 4, 5, 8, -2, 4, -2, -2};
    cout << "For the array ";
    printVec(nums);
    cout << "the pivot index is " << mySol.findPivot(nums) << endl;
    return 0;
}