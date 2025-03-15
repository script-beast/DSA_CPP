#include <bits/stdc++.h>
using namespace std;

bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
        if (S1[j] != '*')
            return false;

    return true;
}

bool isMatch(string s, string p, int sidx, int pidx)
{
}

bool isMatch(string s, string p)
{
}