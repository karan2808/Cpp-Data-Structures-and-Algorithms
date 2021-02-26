#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        const int M = matrix.size(), N = matrix[0].size();
        int row = M - 1, col = 0;
        while (row >= 0 && col < N)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    Solution mySol;
    string s = mySol.searchMatrix(matrix, 8) ? "Yes" : "No";
    cout << "Is the target 8 present in the matrix? " << s << endl;
    return 0;
}