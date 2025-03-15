#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows <= 1)
        return s;
    vector<string> vs(numRows, "");
    int n = s.length(), i = 0;
    while (i < n)
    {
        for (int j = 0; j < numRows && i < n; j++)
            vs[j].push_back(s[i++]);
        for (int j = numRows - 2; j >= 1 && i < n; j--)
            vs[j].push_back(s[i++]);
    }
    string zigzag;
    for (string v : vs)
        zigzag += v;
    return zigzag;
}