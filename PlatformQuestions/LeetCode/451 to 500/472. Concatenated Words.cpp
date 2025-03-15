#include <bits/stdc++.h>
using namespace std;

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_map<string, int> count;
    for (auto word : words)
        count[word]++;

    vector<string> ans;
    for (string word : words)
    {
        int n = word.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i{0}; i < n; i++)
        {
            // if (!dp[i])
            //     continue;
            for (int j = i + 1; j <= n; j++)
                if (j - i < n && count[word.substr(i, j - i)])
                    dp[j] = 1;
            // if (dp[n])
            // {
            //     ans.push_back(word);
            //     break;
            // }
            for (int l : dp)
                cout << l << " ";
            cout << endl;
        }
    }
    return ans;
}