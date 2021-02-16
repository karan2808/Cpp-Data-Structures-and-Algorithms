#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        int last = n - 1;
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            // numbers left
            int left = last - i;
            // while stack is not empty and the numbers left + stack size is greater than k
            // and the current number is less than stack top number, we pop the top
            while (!stk.empty() && left + stk.size() >= k && nums[i] < stk.top())
            {
                stk.pop();
            }
            if (stk.size() < k)
            {
                stk.push(nums[i]);
            }
        }
        vector<int> result;
        // pop off values from the stack and append to result
        while (!stk.empty())
        {
            int val = stk.top();
            stk.pop();
            result.push_back(val);
        }
        reverse(result.begin(), result.end());
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

int main()
{
    vector<int> nums = {3, 5, 2, 9, 5, 4, 10};
    int k = 2;
    Solution MySol;
    cout << "The most competitive subsequence of 3, 5, 2, 9, 5, 4, 10 " << endl;
    printVec(MySol.mostCompetitive(nums, 3));
}