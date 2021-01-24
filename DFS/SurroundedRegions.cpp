#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &board, int row, int col, int Rows, int Cols)
    {
        // check boundary conditions
        if (row >= 0 && col >= 0 && row < Rows && col < Cols && board[row][col] == 'O')
        {
            // flip the value to * and do dfs on its neighbors
            board[row][col] = '*';
            dfs(board, row + 1, col, Rows, Cols);
            dfs(board, row - 1, col, Rows, Cols);
            dfs(board, row, col + 1, Rows, Cols);
            dfs(board, row, col - 1, Rows, Cols);
        }
        return;
    }
    bool ifAtBoundary(int row, int col, int Rows, int Cols)
    {
        if (row == 0 || col == 0 || row == Rows - 1 || col == Cols - 1)
            return true;
        return false;
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int Rows = board.size();
        if (Rows <= 2)
            return;
        int Cols = board[0].size();
        if (Cols <= 2)
            return;
        // traverse through the board
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                // if an O is encountered at the boundary
                if (board[i][j] == 'O' && ifAtBoundary(i, j, Rows, Cols))
                {
                    // do a  dfs and flip all Os to *s
                    dfs(board, i, j, Rows, Cols);
                }
            }
        }
        // flip the Os to Xs and special charater to Os
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '*')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

void printVecVec(vector<vector<char>> board)
{
    for (vector<char> level : board)
    {
        for (char val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board;
    board = {{'X', 'X', 'X', 'X', 'X'},
             {'X', 'X', 'O', 'X', 'O'},
             {'X', 'X', 'O', 'X', 'O'},
             {'X', 'O', 'X', 'X', 'X'},
             {'X', 'O', 'X', 'O', 'O'},
             {'O', 'X', 'O', 'X', 'X'},
             {'O', 'O', 'O', 'X', 'X'}};
    cout << "The original 2D board: ";
    printVecVec(board);
    Solution mySol;
    mySol.solve(board);
    cout << "The new 2D board: ";
    printVecVec(board);
    return 0;
}