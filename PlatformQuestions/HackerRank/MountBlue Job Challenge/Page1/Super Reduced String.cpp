#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s)
{
    string result = "";
    for (long unsigned int i = 0; i < s.size(); i++)
    {
        if (result.size() == 0)
            result.push_back(s[i]);
        else
        {
            if (result[result.size() - 1] == s[i])
                result.pop_back();
            else
                result.push_back(s[i]);
        }
    }
    if (result.size() == 0)
        return "Empty String";
    else
        return result;
}