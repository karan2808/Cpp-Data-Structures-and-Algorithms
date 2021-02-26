#include <iostream>

using namespace std;

class Solution {
    int longestUtil(string s, int start, int end, int k) {
        if (end < k) return 0;
        int count[26] = {0};
        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }
        for (int mid = start; mid < end; mid++) {
            if (count[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && count[s[midNext] - 'a'] < k) midNext++;
            return max(longestUtil(s, start, mid, k), longestUtil(s, midNext, end, k));
        }
        return end - start;
    }
    public:
    int longestSubstring(string s, int k) {
        return longestUtil(s, 0, s.size(), k);
    }
};

int main()
{
    Solution mySol;
    string s = "aaabb";
    int k = 3;
    cout << "The longest substring with at least k repeating characters " << mySol.longestSubstring(s, 3) << endl;
    return 0;
}
