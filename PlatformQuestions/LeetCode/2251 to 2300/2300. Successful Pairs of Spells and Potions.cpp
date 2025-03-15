#include <bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> ans;

    for (int spell : spells)
    {
        int minval = ceil(success / spell);
        auto it = lower_bound(potions.begin(), potions.end(), minval);
        ans.push_back(potions.end() - it);
    }

    return ans;
}