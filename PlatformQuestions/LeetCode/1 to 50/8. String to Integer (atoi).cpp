#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            return 0;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-')
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        long long ans = 0;
        while (i < n && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX)
                return (sign == 1) ? INT_MAX : INT_MIN;
            i++;
        }
        return sign * ans;
    }
};