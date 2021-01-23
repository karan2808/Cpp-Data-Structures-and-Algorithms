#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> result;
        // go from 1 to n
        int i = 1;
        // keep a track of target idx
        int idx = 0;
        // use a stack to simulate the operations
        stack<int> stk;
        // go through each character
        while (i <= n && idx < target.size())
        {
            stk.push(i);
            result.push_back("Push");
            if (stk.top() == target[idx])
            {
                idx++;
                i++;
            }
            else
            {
                result.push_back("Pop");
                i++;
            }
        }
        return result;
    }
};

void print_vec(vector<string> ops)
{
    for (int i = 0; i < ops.size(); i++)
    {
        cout << ops[i] << " ";
    }
}

int main()
{
    Solution mySol;
    vector<int> ex = {2, 3, 4};
    cout << "The operations for n = 5 and target = 2, 3, 4 are: ";
    print_vec(mySol.buildArray(ex, 5));
    cout << endl;
    return 0;
}