#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k)
{
    const int n = blocks.size();
    int ans = INT_MAX;
    int recolors = count(blocks.begin(), blocks.end(), 'W');
    ans = min(ans, recolors);
    for (int l = 0, r = k; r < n; l++, r++)
    {
        recolors += (blocks[r] == 'W') - (blocks[l] == 'W');
        ans = min(ans, recolors);
    }

    return ans;
}