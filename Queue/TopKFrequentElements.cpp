// compile with cpp 14
#include <iostream>
#include <queue>

using namespace std;

class Solution{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz == k) {
            return nums;
        }
        vector<int> result;
        // sort the numbers to easily find the frequencies O(n log n)
        sort(nums.begin(), nums.end());

        // custom compare func
        auto cmp = [](auto a, auto b) {
            return a.second < b.second;
        };
        // use a priority queue to store the elements and their counts
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> newQ(cmp);

        int x = nums[0], currIdx = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i] != x) {
                // push the element and its cound to the queue
                newQ.push({x, i - currIdx});
                x = nums[i];
                // update the last index
                currIdx = i;   
            }
        }
        // get the top k frequent elements
        newQ.push({nums.back(), sz - currIdx});
        for (int i = 0; i < k; i++) {
            result.push_back(newQ.top().first);
            newQ.pop();
        }
        return result;
    }
};

void printVec(vector<int> nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    cout << "The top 2 frequent elements of 1, 1, 1, 2, 2, 3 are ";
    Solution mySol;
    printVec(mySol.topKFrequent(nums, k));
    return 0;
}