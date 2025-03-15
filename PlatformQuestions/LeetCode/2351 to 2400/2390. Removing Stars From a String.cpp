#include <bits/stdc++.h>
using namespace std;

// Using Stacks
string removeStars(string s)
{
    stack<char> st;
    for (char c : s)
        c == '*' ? st.pop() : st.push(c);

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Using Two Pointers
string removeStars(string s)
{
    int n = s.size();
    int i = 0, j = 0;
    while (j < n)
    {
        if (s[j] == '*')
            i--;
        else
            s[i++] = s[j];
        j++;
    }
    return s.substr(0, i);
}

// 2 lines

string removeStars(string s)
{
    string i = "";
    for (char c : s)
        c == '*' ? i.pop_back() : i.push_back(c);
    return i;
}