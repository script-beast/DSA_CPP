#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k)
{
    const int n = blocks.size();
    int recolors = count(blocks.begin(), blocks.begin() + k, 'W');
    int ans = recolors;
    for (int l = 0, r = k; r < n; l++, r++)
    {
        recolors -= blocks[l] == 'W';
        recolors += blocks[r] == 'W';
        ans = min(ans, recolors);
    }

    return ans;
}