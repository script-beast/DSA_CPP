#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int res{0}, n{0}, si = s.length();
    for (int i{0}; i < si; i++)
    {
        if (s[i] == '0')
            res = min(n, res + 1);
        else
            n++;
    }
    return res;
}

int main()
{
}