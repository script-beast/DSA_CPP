#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int st, int e)
{
    while (st < e)
        if (s[st++] != s[e--])
            return false;
    return true;
}

void func(int idx, string s, vector<string> &path, vector<vector<string>> &ans)
{
    if (idx == s.length())
        ans.push_back(path);

    for (int i = idx; i < s.length(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            func(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> path;
    func(0, s, path, ans);
    return ans;
}

//main
int main()
{
    string s = "aab";
    vector<vector<string>> ans;
    ans = partition(s);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}