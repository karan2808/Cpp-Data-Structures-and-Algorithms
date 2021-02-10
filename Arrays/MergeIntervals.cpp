#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int sz = intervals.size();
        vector<vector<int>> result;
        if (sz == 0)
        {
            return result;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        // store the first interval into result
        vector<int> currentInterval = intervals[0];
        result.push_back(currentInterval);

        // use an idx to iterate over the intervals
        int idx = 0;
        for (vector<int> interval : intervals)
        {
            int currEnd = currentInterval[1];
            int nextBegin = interval[0];
            int nextEnd = interval[1];
            // if current end > next begin, the intervals overlap
            if (currEnd >= nextBegin)
            {
                currentInterval[1] = max(currEnd, nextEnd);
                result[idx][1] = currentInterval[1];
            }
            else
            {
                // set the currentInterval to the interval, since there is no overlap
                currentInterval = interval;
                result.push_back(currentInterval);
                idx++;
            }
        }
        return result;
    }
};

void printVecVec(vector<vector<int>> vecvec) {
    for (auto vec: vecvec) {
        for (int i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution mySol;
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {16, 21}};
    vector<vector<int>> result = mySol.merge(nums);
    printVecVec(result);
    return 0;
}