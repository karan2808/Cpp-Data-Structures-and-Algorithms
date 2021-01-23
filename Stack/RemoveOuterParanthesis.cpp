#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Remove
{
public:
    string removeOuterParanthesis(string S)
    {
        // create a stack to keep a track of valid paranthesis
        stack<char> stk;
        string primitiveString = "";

        for (char c : S)
        {
            // if an opening bracket is encountered
            if (c == '(')
            {
                // if the stack has more than one element, we are looking at the inner paranthesis
                if (stk.size() >= 1)
                {
                    primitiveString += "(";
                    stk.push(c);
                }
                else
                {
                    // push only on the stack as it is outer paranthesis
                    stk.push(c);
                }
            }
            else
            {
                // the size of the stack has to be strictly greater than one since the last item left will correspond to outer paranthesis
                if (stk.size() > 1)
                {
                    primitiveString += ")";
                    stk.pop();
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return primitiveString;
    }
};

int main()
{
    Remove rem;
    string input = "(()())(())()(())()";
    cout << "After removing outer paranthesis of (()())(())()(())() the new string is " << rem.removeOuterParanthesis(input) << endl;
    return 0;
}