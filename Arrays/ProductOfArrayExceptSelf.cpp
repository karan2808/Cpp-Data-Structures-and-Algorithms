#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        // compute left and right products separately
        int leftProd[sz];
        vector<int> op(sz, 0);
        leftProd[0] = 1;
        for (int i = 1; i < sz; i++) {
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
        }
        // keep a track of left product
        int R = 1;
        for (int i = sz - 1; i >= 0; i--) {
            op[i] = R * leftProd[i];
            R = R * nums[i];
        }
        return op;
    }
};

void printVec(vector<int> nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return;
}

int main() {
    Solution mySol;
    vector<int> nums = {1, -2, 4, 5, 6, -5, -8};
    cout << "The nums are ";
    printVec(nums);
    cout << "The product of elements except self is ";
    printVec(mySol.productExceptSelf(nums));
    nums = {1, 2, 3, 4};
    cout << "The nums are ";
    printVec(nums);
    cout << "The product of elements except self is ";
    printVec(mySol.productExceptSelf(nums));
    return 0;
}