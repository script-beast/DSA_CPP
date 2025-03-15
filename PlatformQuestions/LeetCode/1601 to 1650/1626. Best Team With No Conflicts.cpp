#include <bits/stdc++.h>
using namespace std;

// recurive
//  int bestTeamScorerec(vector<pair<int, int>> vals, int idx, int prev)
//  {
//      if (idx < 0)
//          return 0;

//     int nottake = bestTeamScorerec(vals, idx - 1, prev);
//     if (prev == -1 || vals[prev].second >= vals[idx].second)
//     {
//         int take = vals[idx].second + bestTeamScorerec(vals, idx - 1, idx);
//         return max(take, nottake);
//     }

//     return nottake;
// }

// int bestTeamScore(vector<int> &scores, vector<int> &ages)
// {
//     int n = scores.size();
//     vector<pair<int, int>> vals;
//     for (int i{0}; i < n; i++)
//         vals.push_back({ages[i], scores[i]});

//     sort(vals.begin(), vals.end());

//     // for (auto i : vals)
//     //     cout << i.first << " " << i.second << endl;

//     return bestTeamScorerec(vals, n - 1, -1);
// }

// Memoization
int bestTeamScorerec(vector<pair<int, int>> vals, int idx, int prev, vector<vector<int>> &dp)
{
    if (idx >= vals.size())
        return 0;

    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    int nottake = bestTeamScorerec(vals, idx + 1, prev, dp);
    if (prev == -1 || vals[prev].second <= vals[idx].second)
    {
        int take = vals[idx].second + bestTeamScorerec(vals, idx + 1, idx, dp);
        return dp[idx][prev + 1] = max(take, nottake);
    }

    return dp[idx][prev + 1] = nottake;
}

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n = scores.size();
    vector<pair<int, int>> vals;
    for (int i{0}; i < n; i++)
        vals.push_back({ages[i], scores[i]});

    sort(vals.begin(), vals.end());

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = bestTeamScorerec(vals, 0, -1, dp);

    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return ans;
}

// tabulation
int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n = scores.size();
    vector<pair<int, int>> vals;
    for (int i = 0; i < n; i++)
        vals.push_back({ages[i], scores[i]});
    sort(vals.begin(), vals.end());
    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = vals[i].second;
        for (int j = 0; j < i; j++)
            if (vals[j].second <= vals[i].second)
                dp[i] = max(dp[i], dp[j] + vals[i].second);

        ans = max(ans, dp[i]);
        // for (int i : dp)
        //     cout << i << " ";
        // cout << endl;
    }

    return ans;
}