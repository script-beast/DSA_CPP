#include <bits/stdc++.h>
using namespace std;

int sockMerchant(int n, vector<int> ar)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[ar[i]]++;

    int count = 0;
    for (auto i : mp)
        count += i.second / 2;

    return count;
}