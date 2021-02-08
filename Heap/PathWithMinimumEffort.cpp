#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // min heap comparator
    struct comparator
    {
        bool operator()(vector<int> const &a, vector<int> const &b)
        {
            return a[2] > b[2];
        }
    };

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // min heap contains <x, y, cost> based on minimum cost
        priority_queue<vector<int>, vector<vector<int>>, comparator> minHeap;

        // get the rows and cols
        int rows = heights.size();
        int cols = heights[0].size();

        // keep track of the visited nodes
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // keep a track of current min cost
        int currCost = 0;

        // make directions
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        // push the current location and current cost
        minHeap.push({0, 0, 0});

        while (!minHeap.empty())
        {
            vector<int> heapTop = minHeap.top();
            minHeap.pop();
            int x = heapTop[0];
            int y = heapTop[1];
            int cost = heapTop[2];

            // update current cost
            currCost = max(cost, currCost);

            // if we reach the bottom right corner
            if (x == rows - 1 && y == cols - 1)
            {
                // return the cost
                return currCost;
            }

            // add current location to visited set
            visited[x][y] = true;

            // for each direction in directions
            for (auto dir : directions)
            {
                // find updated x, y
                int xn = x + dir[0];
                int yn = y + dir[1];

                // check if xn and yn are within bounds and if they have not been visited
                if (xn >= 0 && yn >= 0 && xn < rows && yn < cols && !visited[xn][yn])
                {
                    cost = abs(heights[x][y] - heights[xn][yn]);
                    minHeap.push({xn, yn, cost});
                }
            }
        }
        return 0;
    }
};

void printVecVec(vector<vector<int>> VecVec)
{
    for (auto Vec : VecVec)
    {
        for (auto element : Vec)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution mySol;
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << "The minimum effort path for the given set of heights " << endl;
    printVecVec(heights);
    cout << "is, " << mySol.minimumEffortPath(heights) << endl;
    return 0;
}