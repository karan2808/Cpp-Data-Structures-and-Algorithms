#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int result = 0;
        // loop through the points
        for (int i = 0; i < points.size(); i++)
        {
            // keep a track of the slopes of the lines
            unordered_map<long double, int> h;
            // count if the points are duplicates
            int same = 1;
            // keep a track of local max
            int localMax = 0;
            // for all the points
            for (int j = i + 1; j < points.size(); j++)
            {
                // if duplicates are encountered
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    same++;
                }
                else if (points[i][0] == points[j][0])
                {
                    h[INT_MAX]++;
                } else {
                    // get the slope and increment the count
                    long double slope = (long double)(points[i][1] - points[j][1]) /
                                        (long double)(points[i][0] - points[j][0]);
                    h[slope]++;
                }
            }
            // for every slope find the max count
            for (auto slope : h)
            {
                localMax = max(slope.second, localMax);
            }
            localMax += same;
            // update result
            result = max(result, localMax);
        }
        return result;
    }
};

void printVecVec(vector<vector<int>> &ip)
{
    for (vector<int> pair : ip)
    {
        cout << "{ ";
        for (int val : pair)
        {
            cout << val << " ";
        }
        cout << "}";
        cout << " ";
    }
}

int main()
{
    Solution mySol;
    vector<vector<int>> ip = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    int res = mySol.maxPoints(ip);
    cout << "The maximum number of points on a line for the points ";
    printVecVec(ip);
    cout << res << endl;
    return 0;
}