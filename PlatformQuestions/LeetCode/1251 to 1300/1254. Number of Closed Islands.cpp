#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j])
        return;
    visited[i][j] = 1;
    dfs(i + 1, j, grid, visited);
    dfs(i - 1, j, grid, visited);
    dfs(i, j + 1, grid, visited);
    dfs(i, j - 1, grid, visited);
}

int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited = grid;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0])
            dfs(i, 0, grid, visited);
        if (!visited[i][m - 1])
            dfs(i, m - 1, grid, visited);
    }
    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j])
            dfs(0, j, grid, visited);
        if (!visited[n - 1][j])
            dfs(n - 1, j, grid, visited);
    }
    int count = 0;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }
    return count;
}