#include <bits/stdc++.h>
using namespace std;

// Recursive
int longestPalindromeSubseqrec(string str, int s, int e)
{
    if (s == e)
        return 1;
    if (str[s] == str[e] && s + 1 == e)
        return 2;
    if (str[s] == str[e])
        return longestPalindromeSubseqrec(str, s + 1, e - 1) + 2;
    return max(longestPalindromeSubseqrec(str, s, e - 1), longestPalindromeSubseqrec(str, s + 1, e));
}

int longestPalindromeSubseq(string str)
{
    int n = str.length();
    return longestPalindromeSubseqrec(str, 0, n - 1);
}

// Memoization
int longestPalindromeSubseqMemo(string str, int s, int e, vector<vector<int>> &dp)
{
    if (s == e)
        return 1;
    if (s > e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];

    if (str[s] == str[e])
        return (2 + longestPalindromeSubseqMemo(str, s + 1, e - 1, dp)); // directly return

    int leaveLeft = longestPalindromeSubseqMemo(str, s + 1, e, dp);
    int leaveRight = longestPalindromeSubseqMemo(str, s, e - 1, dp);
    return dp[s][e] = max(leaveLeft, leaveRight);
}

int longestPalindromeSubseq(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return longestPalindromeSubseqMemo(str, 0, n - 1, dp);
}

// Tabulation

int longestPalindromeSubseq(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            dp[i][j] = str[i] == str[j] ? 2 + dp[i + 1][j - 1] : max(dp[i + 1][j], dp[i][j - 1]);

    return dp[0][n - 1];
}
