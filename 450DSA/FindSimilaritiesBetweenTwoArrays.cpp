// https://www.naukri.com/code360/problems/find-similarities-between-two-arrays_1229070
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    // array is unsorted
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    return {n + m - s.size(), s.size()};
}