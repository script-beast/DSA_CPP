#include <bits/stdc++.h>
using namespace std;

void util(vector<int> &nums, int idx, vector<int> &temp, set<vector<int>> &res)
{
    if (idx == nums.size())
    {
        if (temp.size() > 1)
            res.insert(temp);
        return;
    }

    if (!temp.size() || temp.back() >= nums[idx])
    {
        temp.push_back(nums[idx]);
        util(nums, idx + 1, temp, res);
        temp.pop_back();
    }

    util(nums, idx + 1, temp, res);
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> temp;
    set<vector<int>> res;
    util(nums, 0, temp, res);
    // return vector(res.begin(), res.end());
}