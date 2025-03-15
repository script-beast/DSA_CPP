#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    func(nums, idx + 1, ds, ans);
    ds.push_back(nums[idx]);
    func(nums, idx + 1, ds, ans);
    ds.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;

    func(nums, 0, ds, ans);

    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}