#include <bits/stdc++.h>
using namespace std;

// Recursive
int fibrec(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibrec(n - 1) + fibrec(n - 2);
}

int fib(int n)
{
    return fibrec(n);
}

// Memoization
int fibMemo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return fibMemo(n, dp);
}

// Tabulation

int fib(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Space Optimized Tabulation

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}