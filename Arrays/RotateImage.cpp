#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // first reverse the rows of the matrix
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i > j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
};

void printVecVec(vector<vector<int>> &img)
{
    for (vector<int> row : img)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> img = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    Solution mySol;
    printVecVec(img);
    mySol.rotate(img);
    cout << endl;
    printVecVec(img);
    return 0;
}