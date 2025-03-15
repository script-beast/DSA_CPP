#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto i : s)
        mp[i]++;
    for (auto i : t)
        if (mp[i] > 0)
            mp[i]--;
        else
            return false;
    for (auto i : mp)
        if (i.second != 0)
            return false;
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";
    cout << isAnagram(s, t) << endl;

    return 0;
}