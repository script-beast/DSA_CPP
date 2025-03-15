#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            cnt++;
        else
        {
            ans = ans + (cnt * (cnt + 1) / 2);
            cnt = 0;
        }
    }
    ans = ans + (cnt * (cnt + 1) / 2);

    return ans;
}