#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isValid(string S)
    {
        // keep a track of the brackets
        stack<char> stk;
        // store the valid pairs in a map
        unordered_map<char, char> p_map;
        p_map[')'] = '(';
        p_map[']'] = '[';
        p_map['}'] = '{';
        for (char c : S)
        {
            // if opening bracket
            if (c == '(' || c == '[' || c == '{')
            {
                // push onto stack
                stk.push(c);
            }
            else
            {
                // if something is on the stack, check if its a valid closing braket,
                // if it is, pop it
                if (stk.size() > 0 && stk.top() == p_map[c])
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution mySol;
    string s1 = "{}()[(){}{[]}]";
    string s2 = "{}(){[(){}{[]}]";
    string s3 = "{}()[(}){}{[]}]";
    string isValid1 = mySol.isValid(s1) ? "Yes" : "No";
    string isValid2 = mySol.isValid(s2) ? "Yes" : "No";
    string isValid3 = mySol.isValid(s3) ? "Yes" : "No";
    cout << "Is {}()[(){}{[]}] valid? " << isValid1 << endl;
    cout << "Is {}(){[(){}{[]}] valid? " << isValid2 << endl;
    cout << "Is {}()[(}){}{[]}] valid? " << isValid3 << endl;
    return 0;
};