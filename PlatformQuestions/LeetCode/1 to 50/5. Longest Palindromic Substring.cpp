#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    long long n = s.size();
    for (long long i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

string longestPalindrome(string s)
{
    long long n = s.size();
    string result = "";
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
        {
            string sub = s.substr(i, j - i);
            if (isPalindrome(sub) && sub.size() > result.size())
                result = sub;
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    string result = longestPalindrome(s);
    cout << result << endl;
    return 0;
}