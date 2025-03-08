// https://www.naukri.com/code360/problems/move-all-negative-numbers-to-beginning-and-positive-to-end_1112620
#include <bits/stdc++.h>
using namespace std;

vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (nums[i] < 0)
            i++;
        else if (nums[j] >= 0)
            j--;
        else
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {-23, 48, -13, 31, -12, 6, -42, 23, 14, 33, -33, -21, 0, 25, -39, -31};
    vector<int> result = separateNegativeAndPositive(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}