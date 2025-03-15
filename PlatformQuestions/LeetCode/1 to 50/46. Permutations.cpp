#include <bits/stdc++.h>
using namespace std;

// approach 1
void func(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, bool freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = true;
            func(nums, ds, ans, freq);
            freq[i] = false;
            ds.pop_back();
        }
    }
}

// approach 2

void func2(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        func2(idx + 1, nums, ans);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    // vector<int> ds;
    // bool freq[nums.size()];
    // for (int i{0}; i < nums.size(); i++)
    //     freq[i] = false;
    // func(nums, ds, ans, freq);

    func2(0, nums, ans);

    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}