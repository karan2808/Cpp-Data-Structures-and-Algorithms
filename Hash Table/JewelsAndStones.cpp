#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> stoneMap;
        int count = 0;
        for (char c : jewels)
        {
            stoneMap[c]++;
        }
        for (char c : stones)
        {
            if (stoneMap.find(c) != stoneMap.end())
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution mySol;
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout << "The total number of stones that are also jewels are " << mySol.numJewelsInStones(jewels, stones) << endl;
    return 0;
}