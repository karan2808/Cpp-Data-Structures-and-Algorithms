#include <iostream>
#include <string> 
#include <vector>

using namespace std;
class Solve {
    public:
    bool isMatch(string s, string p) {
        // make a dp matrix
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // 0 letters match 
        dp[0][0] = true;
        // if the previous letter is *, whether the strings match depends on the dp value before that letter
        for (int j = 2; j <= p.size(); j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        // fill the dp matrix
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                // if the prev letter is '.' or if the letters are the same
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    // check the rest of the pattern
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // we need to check two characters back 
                    dp[i][j] = dp[i][j-2];
                    // if we have a . two characters back 
                    // if char at two steps back in the pattern is same as char at 1 step back in string
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                } else {
                    // we don't have a match
                    dp[i][j]= false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main(){
    Solve regEx;
    string s = "ab";
    string p = ".*";
    string m = regEx.isMatch(s, p) ? "is a match" : "is not a match";
    cout << "the string ab and pattern .* is " << m << endl;
    return 0;
}