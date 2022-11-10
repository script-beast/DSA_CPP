#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "({[]})";
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
            s.push(str[i]);
        else if ((str[i] == ')' && s.top() == '(') ||
                 (str[i] == '}' && s.top() == '{') ||
                 (str[i] == ']' && s.top() == '['))
            s.pop();
        else
            s.push(str[i]);
    }
    string ans = s.empty() ? "Valid" : "Invalid";
    cout << ans;

    return 0;
}