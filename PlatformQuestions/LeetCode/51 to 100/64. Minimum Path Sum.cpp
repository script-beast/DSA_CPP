#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    vector<int> dp(grid[0].size() + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
            dp[j + 1] = min(dp[j], dp[j + 1]) + grid[i][j];
        dp[0] = INT_MAX;
    }
    return dp.back();
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}