#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> M)
    {
        int rows = M.size(), cols = M[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int count = 0;
                // check the neighbors of the current cell
                for (int nr = r - 1; nr <= r + 1; nr++)
                {
                    for (int nc = c - 1; nc <= c + 1; nc++)
                    {
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                        {
                            ans[r][c] += M[nr][nc];
                            count++;
                        }
                    }
                }
                ans[r][c] /= count;
            }
        }
        return ans;
    }
};

void printVecVec(vector<vector<int>> ans)
{
    for (vector<int> vec : ans)
    {
        for (int v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> M = {{1, 0, 2, 3, 4}, {3, 2, 1, 4, 5}, {5, 6, 4, 3, 1}, {7, 5, 4, 2, 1}};
    Solution mySol;
    printVecVec(mySol.imageSmoother(M));
    return 0;
}