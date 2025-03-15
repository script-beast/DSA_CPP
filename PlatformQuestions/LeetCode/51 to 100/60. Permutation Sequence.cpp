#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans = "";
    while (1)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 1)
        {
            ans += to_string(nums[0]);
            break;
        }
        k %= fact;
        fact /= nums.size();
    }
    return ans;
}

int main()
{
    cout << getPermutation(3, 3) << endl;
    return 0;
}