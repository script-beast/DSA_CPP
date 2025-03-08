#include <bits/stdc++.h>
using namespace std;

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr2.begin(), arr2.end());
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    int n = arr1.size(), m = arr2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (arr1[i - 1] > dp[i - 1][j])
                dp[i][j] = arr1[i - 1];
            if (j > 0)
            {
                auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
                if (it != arr2.end())
                    dp[i][j] = min(dp[i][j], *it);
            }
        }
    }
    for (int j = 0; j <= m; j++)
        if (dp[n][j] != INT_MAX)
            return j;
    return -1;
}