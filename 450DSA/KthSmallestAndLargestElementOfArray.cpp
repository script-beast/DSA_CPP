// https://www.naukri.com/code360/problems/kth-smallest-and-largest-element-of-array_1115488
#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> res;
    sort(arr.begin(), arr.end());
    res.push_back(arr[k - 1]);
    res.push_back(arr[n - k]);
    return res;
}