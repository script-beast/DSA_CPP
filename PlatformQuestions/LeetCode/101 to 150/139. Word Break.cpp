#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool func(string s, unordered_set<string> &dict, unordered_map<string, bool> &dp)
    {
        if (s.size() == 0)
            return true;

        if (dp.find(s) != dp.end())
            return dp[s];

        for (int i = 1; i <= s.size(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (dict.find(left) != dict.end() && func(right, dict, dp))
                return dp[s] = true;
        }

        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        unordered_map<string, bool> dp;

        for (string word : wordDict)
            dict.insert(word);

        return func(s, dict, dp);
    }
};