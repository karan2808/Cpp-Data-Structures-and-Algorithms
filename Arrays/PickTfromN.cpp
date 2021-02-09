#include <iostream>
#include <vector>
#include <unordered_set>
#include <time.h>

using namespace std;

class Solution{
    public:
    vector<int> pickTfromN(vector<int> nums, int T) {
        // set the random seed
        srand(time(0));
        
        // store the result in an array
        vector<int> result;

        // get the total size of nums
        int sz = nums.size();
        // Total complexity O(T N)
        // O(T)
        for (int i = 0; i < T; i++) {

            // get the random index
            int randidx = rand() % sz;
            
            // append to result
            result.push_back(nums[randidx]);

            // remove that element from the vector O(N)
            nums.erase(nums.begin() + randidx);

            // decrement size
            sz--;
        }
        
        return result;
    }
};

void printVec(vector<int> nums) {
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution mySol;
    vector<int> result = mySol.pickTfromN(nums, 3);
    printVec(result);
    return 0;
}