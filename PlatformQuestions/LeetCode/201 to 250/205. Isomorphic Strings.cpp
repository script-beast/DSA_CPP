#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    vector<int> m1(256), m2(256);
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    string t{""}, s{""};

    cin >> t;
    cin >> s;

    cout << isIsomorphic(t, s);
}
