#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    int a = 0;
    int b = nums[0];

    for (int i = 2; i <= n; i++)
    {
        int c = max(b, a + nums[i - 1]);
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << rob(nums) << endl;
    return 0;
}