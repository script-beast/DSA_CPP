#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int ans{0};

    int poinGreed{0}, poinSize{0};
    int lenGreed = g.size(), lenSize = s.size();

    while (poinGreed < lenGreed && poinSize < lenSize)
    {

        if (g[poinGreed] <= s[poinSize])
        {
            poinGreed++;
            ans++;
        }
        // else if (g[poinGreed] < s[poinSize])
        //     poinGreed++;
        // else
        poinSize++;
    }

    return ans;
}