#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        int sz = s.size();
        stack<int> counts;
        stack<string> result;
        string res = "";
        int index = 0;
        // go through each letter
        while (index < sz)
        {
            // if we encounter a digit
            if (isdigit(s[index]))
            {
                int count = 0;
                // get the count
                while (isdigit(s[index]))
                {
                    count = count * 10 + (s[index] - '0');
                    index++;
                }
                // push the count on the stack to keep a track
                counts.push(count);
            }
            else if (s[index] == '[')
            {
                // if an opening bracket is encountered, push result onto stack and reset
                result.push(res);
                res = "";
                index++;
            }
            else if (s[index] == ']')
            {
                // if a closing bracket is encountered update result
                string temp = result.top();
                int count = counts.top();
                result.pop();
                counts.pop();
                // add the current char/string to previous result count times
                while (count)
                {
                    temp += res;
                    count--;
                }
                // update result
                res = temp;
                index++;
            }
            else
            {
                // add char to result
                res += s[index];
                index++;
            }
        }
        return res;
    }
};

int main()
{
    Solution mySol;
    string s1 = "3[a]2[bc]";
    string s2 = "2[3[z]4[g]3[y3[t1[u]]]]";
    cout << "Decoded string for the sequence 3[a]2[bc] is " << mySol.decodeString(s1) << endl;
    cout << "Decoded string for the sequence 2[3[z]4[g]3[y3[t1[u]]]] is " << mySol.decodeString(s2) << endl;
    return 0;
}