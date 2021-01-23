#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> stk;
        stk.push(S[0]);
        string S_WoDup;
        // iterate over the string and remove duplicates
        for (int i = 0; i < S.size(); i++)
        {
            if (!stk.empty() && stk.top() == S[i])
            {
                stk.pop();
                continue;
            }
            stk.push(S[i]);
        }
        // get the string without duplicates from stack
        while (!stk.empty())
        {
            S_WoDup += stk.top();
            stk.pop();
        }
        // reverse the string to put it in the right order
        reverse(S_WoDup.begin(), S_WoDup.end());
        return S_WoDup;
    }
};

int main()
{
    Solution mySol;
    string s = "abbacaccdesfffst";
    cout << "After removing duplicates from abbacaccdesfffst: " << mySol.removeDuplicates(s) << endl;
    return 0;
}
