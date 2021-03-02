#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return {};
        int row = matrix.size();
        int col = matrix[0].size();
        int idx = 0;
        vector<int> ans(row * col);
        int i = 0;
        int j = 0;
        while (i < row and j < col)
        {
            while (i >= 0 and j < col)
            {
                ans[idx] = matrix[i][j];
                idx++;
                i--;
                j++;
            }
            i++;
            if (j == col)
            {
                j--;
                i++;
            }
            while (j >= 0 and i < row)
            {
                ans[idx] = matrix[i][j];
                idx++;
                i++;
                j--;
            }
            j++;
            if (i == row)
            {
                i--;
                j++;
            }
        }
        return ans;
    }
};

void printVec(vector<int> diag)
{
    for (int &v : diag)
    {
        cout << v << " ";
    }
    cout << endl;
}

void printVecVec(vector<vector<int>> matrix)
{
    for (vector<int> vec : matrix)
    {
        for (int v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    Solution mySol;
    cout << "For the matrix " << endl;
    printVecVec(matrix);
    cout << "The diagonal elements are " << endl;
    printVec(mySol.findDiagonalOrder(matrix));
}