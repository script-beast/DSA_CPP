#include <bits/stdc++.h>
using namespace std;

// recursive solution
// int mincostTicketsrec(vector<int> &days, vector<int> &costs, int i, int n)
// {
//     if (i >= n)
//         return 0;
//     int ans = INT_MAX;
//     int j = i;
//     while (j < n && days[j] - days[i] < 7)
//         j++;
//     ans = min(ans, mincostTicketsrec(days, costs, j, n) + costs[1]);
//     j = i;
//     while (j < n && days[j] - days[i] < 30)
//         j++;
//     ans = min(ans, mincostTicketsrec(days, costs, j, n) + costs[2]);
//     ans = min(ans, mincostTicketsrec(days, costs, i + 1, n) + costs[0]);
//     return ans;
// }

// int mincostTickets(vector<int> &days, vector<int> &costs)
// {
//     int n = days.size();
//     return mincostTicketsrec(days, costs, 0, n);
// }

// memoization solution
int mincostTicketsmemo(vector<int> &days, vector<int> &costs, int i, int n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    int j = i;
    while (j < n && days[j] - days[i] < 7)
        j++;
    ans = min(ans, mincostTicketsmemo(days, costs, j, n, dp) + costs[1]);
    j = i;
    while (j < n && days[j] - days[i] < 30)
        j++;
    ans = min(ans, mincostTicketsmemo(days, costs, j, n, dp) + costs[2]);
    ans = min(ans, mincostTicketsmemo(days, costs, i + 1, n, dp) + costs[0]);
    return dp[i] = ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n, -1);
    mincostTicketsmemo(days, costs, 0, n, dp);

    // for (int i : dp)
    //     cout << i << " ";

    return 0;
}

// tabulation solution

// int mincostTickets(vector<int> &days, vector<int> &costs)
// {
//     int n = days.size();
//     vector<int> dp(n, 0);
//     dp[0] = costs[0];
//     for (int i = 1; i < n; i++)
//     {
//         int ans = INT_MAX;
//         int j = i;
//         while (j >= 0 && days[i] - days[j] < 7)
//             j--;
//         if (j >= 0)
//             ans = min(ans, dp[j] + costs[1]);
//         else
//             ans = min(ans, costs[1]);
//         j = i;
//         while (j >= 0 && days[i] - days[j] < 30)
//             j--;
//         if (j >= 0)
//             ans = min(ans, dp[j] + costs[2]);
//         else
//             ans = min(ans, costs[2]);
//         ans = min(ans, dp[i - 1] + costs[0]);
//         dp[i] = ans;
//     }
//     return dp[n - 1];
// }

int main()
{
    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};
    cout << mincostTickets(days, costs);
    return 0;
}