#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
    public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Queue;
        for (int num: nums) {
            Queue.push(num);
            while (Queue.size() > k) {
                Queue.pop();
            }
        }
        return Queue.top();
    }
};

int main() {
    KthLargest KL;
    vector<int> nums = {1, 2, 3, 4, 5, 43 , -1, 333, -9, 321, 44};
    cout << KL.findKthLargest(nums, 2) << endl;
    cout << KL.findKthLargest(nums, 4) << endl;
    cout << KL.findKthLargest(nums, 6) << endl;
    cout << KL.findKthLargest(nums, 1) << endl;
    cout << KL.findKthLargest(nums, 8) << endl;
    return 0;
}