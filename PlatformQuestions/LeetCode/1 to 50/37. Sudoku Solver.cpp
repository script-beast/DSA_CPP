#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char val)
{
    for (int i{0}; i < 9; i++)
    {
        if (board[i][col] == val)
            return false;
        if (board[row][i] == val)
            return false;
        if (board[((row / 3) * 3) + i / 3][((col / 3) * 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solver(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return true;
    if (col == 9)
        return solver(board, row + 1, 0);
    if (board[row][col] != '.')
        return solver(board, row, col + 1);

    for (char i{'1'}; i <= '9'; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (solver(board, row, col + 1))
                return true;
        }
        board[row][col] = '.';
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    solver(board, 0, 0);
}

int main()
{
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}