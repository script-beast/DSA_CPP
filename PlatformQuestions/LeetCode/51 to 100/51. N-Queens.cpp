#include <bits/stdc++.h>
using namespace std;

void slove(vector<string> &boards, int col, vector<vector<string>> &ans, int n, vector<bool> &saferow, vector<bool> &safeUpperDai, vector<bool> &safeLowerDai)
{
    if (col == n)
    {
        ans.push_back(boards);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int lowD = i + col;
        int upD = n - 1 + col - i;
        if (!saferow[i] && !safeLowerDai[lowD] && !safeUpperDai[upD])
        {
            boards[i][col] = 'Q';
            saferow[i] = true;
            safeLowerDai[lowD] = true;
            safeUpperDai[upD] = true;
            slove(boards, col + 1, ans, n, saferow, safeUpperDai, safeLowerDai);
            boards[i][col] = '.';
            saferow[i] = false;
            safeLowerDai[lowD] = false;
            safeUpperDai[upD] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> boards(n);
    string s(n, '.');
    for (int i{0}; i < n; i++)
        boards[i] = s;

    vector<bool> saferow(n, false), safeUpperDai(2 * (n - 1), false), safeLowerDai(2 * (n - 1), false);
    slove(boards, 0, ans, n, saferow, safeUpperDai, safeLowerDai);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << endl;
        cout << endl;
    }

    return 0;
}