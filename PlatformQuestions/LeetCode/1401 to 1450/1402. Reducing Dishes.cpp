#include <bits/stdc++.h>
using namespace std;

int maxSatisfaction(vector<int> &satisfaction, int i, int n, int sum)
{
    vector<int> v = satisfaction;
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0, ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (sum + v[i] > 0)
        {
            ans += sum + v[i];
            sum += v[i];
        }
    }
    return ans;
}
