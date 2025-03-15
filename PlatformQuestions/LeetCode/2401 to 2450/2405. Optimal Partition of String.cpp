#include <bits/stdc++.h>
using namespace std;

int partitionString(string s)
{
    int n = s.length();

    unordered_set<char> st;
    int ans = 0;

    for (int i{0}; i < n; i++)
    {
        if (st.find(s[i]) == st.end())
            st.insert(s[i]);
        else
        {
            ans++;
            st.clear();
            st.insert(s[i]);
        }
    }

    return ans + 1;
}