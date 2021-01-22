#include <iostream>
#include <vector>

using namespace std;

class Solve
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        // make a dp array
        int *dp = new int[n + 1];
        // only one way to decode 0 strings
        dp[0] = 1;
        // we have no ways of decoding 0
        dp[1] = s[0] == '0' ? 0 : 1;
        // fill the dp array
        for (int i = 2; i <= n; i++)
        {
            // we can either decode 1 digit into a character
            int oneDigit = stoi(s.substr(i - 1, 1));
            // or two digits into a character
            int twoDigits = stoi(s.substr(i - 2, 2));
            // if the digit is greater than 1 add the dp val
            if (oneDigit >= 1)
            {
                dp[i] += dp[i - 1];
            }
            // add number of ways to decode two digit nums
            if (twoDigits >= 10 && twoDigits <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solve mySol;
    string s1 = "12";
    string s2 = "15425452987";
    cout << "Num ways to decode string 12: " << mySol.numDecodings(s1) << endl;
    cout << "Num ways to decode string 15425452987: " << mySol.numDecodings(s2) << endl;
    return 0;
}