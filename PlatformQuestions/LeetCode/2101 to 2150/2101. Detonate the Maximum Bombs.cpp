#include <bits/stdc++.h>
using namespace std;

int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    int m = bombs[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = bombs[i][0];
        int k = bombs[i][1];
        int l = bombs[i][2];
        int r = bombs[i][3];
        int count = 0;
        for (int x = j; x <= l; x++)
        {
            for (int y = k; y <= r; y++)
            {
                if (bombs[x][y] == 1)
                    count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}