#include <bits/stdc++.h>
using namespace std;

// recursive
bool stoneGamerec(vector<int> &piles, int i, int j, int alex, int lee, bool alexturn)
{
    if (i > j)
        return alex > lee;

    if (alexturn)
    {
        return stoneGamerec(piles, i + 1, j, alex + piles[i], lee, !alexturn) ||
               stoneGamerec(piles, i, j - 1, alex + piles[j], lee, !alexturn);
    }
    else
    {
        return stoneGamerec(piles, i + 1, j, alex, lee + piles[i], !alexturn) ||
               stoneGamerec(piles, i, j - 1, alex, lee + piles[j], !alexturn);
    }
}

bool stoneGame(vector<int> &piles)
{
    return stoneGamerec(piles, 0, piles.size() - 1, 0, 0, true);
}

// memoization
bool stoneGamerec(vector<int> &piles, int i, int j, int alex, int lee, bool alexturn, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return alex > lee;

    if (dp[i][j][alexturn] != -1)
        return dp[i][j][alexturn];

    if (alexturn)
    {
        return dp[i][j][alexturn] = stoneGamerec(piles, i + 1, j, alex + piles[i], lee, !alexturn, dp) ||
                                    stoneGamerec(piles, i, j - 1, alex + piles[j], lee, !alexturn, dp);
    }
    else
    {
        return dp[i][j][alexturn] = stoneGamerec(piles, i + 1, j, alex, lee + piles[i], !alexturn, dp) ||
                                    stoneGamerec(piles, i, j - 1, alex, lee + piles[j], !alexturn, dp);
    }
}

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return stoneGamerec(piles, 0, piles.size() - 1, 0, 0, true, dp);
}

// tabulation
bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    for (int i = 0; i < n; i++)
    {
        dp[i][i][0] = piles[i];
        dp[i][i][1] = 0;
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            dp[i][j][0] = max(piles[i] + dp[i + 1][j][1], piles[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }

    return dp[0][n - 1][0] > dp[0][n - 1][1];
}

// trick
bool stoneGame(vector<int> &piles)
{
    return true;
}