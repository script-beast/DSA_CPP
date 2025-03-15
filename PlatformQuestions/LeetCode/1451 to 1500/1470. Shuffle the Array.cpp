#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans(2 * n);

    for (int i{0}; i < n; i++)
    {
        ans.push_back(i);
        ans.push_back(n + i);
    }

    return ans;
}