#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> trust1(n + 1, 0), trust2(n + 1, 0);
    for (auto i : trust)
    {
        trust1[i[0]]++;
        trust2[i[1]]++;
    }

    for (int i{1}; i <= n; i++)
    {
        if (!trust1[i] && trust2[i] == n - 1)
            return i;
    }
    return -1;
}