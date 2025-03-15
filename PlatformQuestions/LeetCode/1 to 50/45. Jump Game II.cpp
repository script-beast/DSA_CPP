#include <bits/stdc++.h>
using namespace std;

// recursive
// int jumprec(vector<int> &nums, int idx)
// {
//     int n = nums.size();
//     if (idx >= n)
//         return 1e8;
//     if (idx == n - 1)
//         return 0;

//     int ans = INT_MAX;
//     int j = nums[idx];

//     for (int i{1}; i <= min(j, n - idx); i++)
//     {
//         int temp = 1 + jumprec(nums, idx + i);
//         ans = min(ans, temp);
//     }

//     return ans;
// }

// int jump(vector<int> &nums)
// {
//     return jumprec(nums, 0);
// }

// memoization
// int jumpmemo(vector<int> &nums, int idx, vector<int> &dp)
// {
//     int n = nums.size();
//     if (idx >= n)
//         return 1e8;
//     if (idx == n - 1)
//         return 0;

//     if (dp[idx] != -1)
//         return dp[idx];

//     int ans = 1e8;
//     int j = nums[idx];

//     for (int i{1}; i <= min(j, n - idx); i++)
//     {
//         int temp = 1 + jumpmemo(nums, idx + i, dp);
//         ans = min(ans, temp);
//     }

//     return dp[idx] = ans;
// }

// int jump(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return jumpmemo(nums, 0, dp);
// }

// tabulation
// int jump(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n + 1, 0);

//     int ans = 1e8;

//     for (int i{n - 2}; i >= 0; i--)
//     {
//         int val = nums[i];
//         int locmin = 1e8;

//         for (int j{i + 1}; j <= min(val + i, n); j++)
//         {
//             int temp = 1 + dp[j];
//             locmin = min(temp, locmin);
//         }
//         dp[i] = locmin;
//     }
//     return dp[0];
// }

//Greedy

int jump(vector<int> &nums)
{
    int ans = 0, left = 0, right = 0;
    while (right < nums.size() - 1)
    {
        int maxi = 0;
        for (int i = left; i <= right; i++)
            maxi = max(maxi, i + nums[i]);
        left = right + 1;
        right = maxi;
        ans++;
    }

    return ans;
}
