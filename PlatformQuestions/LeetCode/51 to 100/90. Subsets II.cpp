#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        func(nums, i + 1, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    func(nums, 0, ds, ans);
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}