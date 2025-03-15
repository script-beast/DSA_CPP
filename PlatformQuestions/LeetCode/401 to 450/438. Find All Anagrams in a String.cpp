#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int n = s.length();
    int m = p.length();

    if (s.size() < p.size())
        return {};

    vector<int> pfeq(26, 0);
    vector<int> sfeq(26, 0);

    for (int i = 0; i < m; i++)
        pfeq[p[i] - 'a']++, sfeq[s[i] - 'a']++;

    vector<int> ans;

    if (pfeq == sfeq)
        ans.push_back(0);

    for (int i = m; i < n; i++)
    {
        sfeq[s[i - m] - 'a']--;
        sfeq[s[i] - 'a']++;

        if (pfeq == sfeq)
            ans.push_back(i - m + 1);
    }
    return ans;
}