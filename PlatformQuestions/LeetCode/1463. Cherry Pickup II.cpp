#include <bits/stdc++.h>
using namespace std;

// recursive
int cherryPickuprec(vector<vector<int>> &grid, int r, int c1, int c2)
{
    if (r == grid.size())
        return 0;

    int ans = 0;
    for (int i = -1; i <= 1; i++)
    {
        int nc1 = c1 + i;
        if (nc1 < 0 || nc1 >= grid[0].size())
            continue;

        for (int j = -1; j <= 1; j++)
        {
            int nc2 = c2 + j;
            if (nc2 < 0 || nc2 >= grid[0].size())
                continue;

            ans = max(ans, cherryPickuprec(grid, r + 1, nc1, nc2));
        }
    }

    return ans + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
}

int cherryPickup(vector<vector<int>> &grid)
{
    return cherryPickuprec(grid, 0, 0, grid[0].size() - 1);
}

// memoization
int cherryPickuprec(vector<vector<int>> &grid, int r, int c1, int c2, vector<vector<vector<int>>> &dp)
{
    if (r == grid.size())
        return 0;

    if (dp[r][c1][c2] != -1)
        return dp[r][c1][c2];

    int ans = 0;
    for (int i = -1; i <= 1; i++)
    {
        int nc1 = c1 + i;
        if (nc1 < 0 || nc1 >= grid[0].size())
            continue;

        for (int j = -1; j <= 1; j++)
        {
            int nc2 = c2 + j;
            if (nc2 < 0 || nc2 >= grid[0].size())
                continue;

            ans = max(ans, cherryPickuprec(grid, r + 1, nc1, nc2, dp));
        }
    }

    return dp[r][c1][c2] = ans + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return cherryPickuprec(grid, 0, 0, grid[0].size() - 1, dp);
}

// tabulation
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));

    for (int r = n - 1; r >= 0; r--)
    {
        for (int c1 = 0; c1 < m; c1++)
        {
            for (int c2 = 0; c2 < m; c2++)
            {
                int ans = 0;
                for (int i = -1; i <= 1; i++)
                {
                    int nc1 = c1 + i;
                    if (nc1 < 0 || nc1 >= m)
                        continue;

                    for (int j = -1; j <= 1; j++)
                    {
                        int nc2 = c2 + j;
                        if (nc2 < 0 || nc2 >= m)
                            continue;

                        ans = max(ans, dp[r + 1][nc1][nc2]);
                    }
                }

                dp[r][c1][c2] = ans + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
            }
        }
    }

    return dp[0][0][m - 1];
}