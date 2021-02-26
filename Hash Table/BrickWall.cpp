#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> bricks;
        int row, col, result = 0, sum = 0;
        for (row = 0; row < wall.size(); row++) {
            sum = 0;
            for (col = 0; col < wall[row].size() - 1; col++) {
                // add the current brick to the sum
                sum += wall[row][col];
                // increment the count of current sum
                bricks[sum]++;
                // store the max count, of the bricks such that the cost adds up to sum
                // we can draw a line after these bricks to get the min cost
                result = max(result, bricks[sum]);
            }
        }
        return wall.size() - result;
    }
};

void printVecVec(vector<vector<int>> &bricks) {
    for (vector<int> level: bricks) {
        for (int b: level) {
            cout << b << " ";
        }
        cout << endl;
    }
}


int main() {
    Solution mySol;
    vector<vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
    cout << "For the wall ";
    printVecVec(wall);
    cout << "The line that crosses least nbumber of bricks goes through " << mySol.leastBricks(wall) << endl;
    return 0;
}