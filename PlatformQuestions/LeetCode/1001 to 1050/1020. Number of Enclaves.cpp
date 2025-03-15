#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] == 0)
            return;
        A[i][j] = 0;
        dfs(A, i + 1, j);
        dfs(A, i - 1, j);
        dfs(A, i, j + 1);
        dfs(A, i, j - 1);
    }

public:
    int numEnclaves(vector<vector<int>> &A)
    {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < n; i++)
        {
            if (A[i][0] == 1)
                dfs(A, i, 0);
            if (A[i][m - 1] == 1)
                dfs(A, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            if (A[0][i] == 1)
                dfs(A, 0, i);
            if (A[n - 1][i] == 1)
                dfs(A, n - 1, i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans += A[i][j];
        return ans;
    }
};