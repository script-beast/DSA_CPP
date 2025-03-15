#include <bits/stdc++.h>
using namespace std;

// Recursive
int tribonacciRec(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return tribonacciRec(n - 1) + tribonacciRec(n - 2) + tribonacciRec(n - 3);
}

int tribonacci(int n)
{
    return tribonacciRec(n);
}

// Memoization
int tribonacciMemo(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = tribonacciMemo(n - 1, dp) + tribonacciMemo(n - 2, dp) + tribonacciMemo(n - 3, dp);
}

int tribonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return tribonacciMemo(n, dp);
}

// Tabulation

int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    vector<int> dp(n + 1, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n];
}