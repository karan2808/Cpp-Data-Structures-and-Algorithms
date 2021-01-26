#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        // get the size of the string
        int size = s.size();
        int minInsertionsToBalance = 0;
        int stackSize = 0;
        for (int i = 0; i < size; i++)
        {
            // if opening bracket encountered, push it on to stack
            if (s[i] == '(')
            {
                stackSize++;
            }
            else
            {
                // if two sucessive closing brackets, move forward
                if (i + 1 < size && s[i + 1] == ')')
                {
                    i += 1;
                }
                else
                {
                    // if only one closing bracket, an insertion is required
                    minInsertionsToBalance++;
                }
                // update stack size, do a pop operation
                // if there are only closing brackets, we need to insert opening brackets
                if (stackSize == 0)
                {
                    minInsertionsToBalance++;
                }
                else
                {
                    // we need to pop element from stack
                    stackSize--;
                }
            }
        }
        // if elements left on the stack, twice the amount of insertions will be required
        minInsertionsToBalance += stackSize * 2;
        return minInsertionsToBalance;
    }
};

int main () {
    Solution mySol;
    string s1 = "()(()))((((((";
    string s2 = "()))";
    int n1 = mySol.minInsertions(s1);
    int n2 = mySol.minInsertions(s2);
    cout << "The min insertions to balance ()(()))(((((( are " << n1 << endl;
    cout << "The min insertions to balance ())) are " << n2 << endl;
}