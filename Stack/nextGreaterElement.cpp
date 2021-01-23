#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hash;
        stack<int> stk;
        for (int i = 0; i < nums2.size(); i++)
        {
            // if stack is empty, the current number goes on it
            if (stk.empty())
            {
                stk.push(nums2[i]);
            }
            else
            {
                // look for the next greater element,
                // this element will be the next greater for all current elements in stack
                while (!stk.empty() && nums2[i] > stk.top())
                {
                    hash[stk.top()] = nums2[i];
                    stk.pop();
                }
                // push the element on to stack
                stk.push(nums2[i]);
            }
        }
        // for the left over elements, there is no next greater element so equate to -1
        while (!stk.empty())
        {
            hash[stk.top()] = -1;
            stk.pop();
        }
        // for each number in num1, a subset of num2, get the next greater element.
        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = hash[nums1[i]];
        }
        return nums1;
    }
};

int main()
{
    Solution mySol;
    vector<int> nums1 = {4, 2, 3, 9, 1};
    vector<int> nums2 = {5, 4, 3, 2, 1, 2, 0, 9};
    vector<int> ans = mySol.nextGreaterElement(nums1, nums2);
    cout << "Next greater elements for nums1 = {4, 2, 3, 9, 1} and nums2 = {5, 4, 3, 2, 1, 2, 0, 9} ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}