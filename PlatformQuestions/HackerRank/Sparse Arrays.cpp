#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries)
{
    unordered_map<string, int> count;

    for (string i : stringList)
        count[i]++;

    vector<int> ans;

    for (string i : queries)
        ans.push_back(count[i]);

    return ans;
}