// https://www.naukri.com/code360/problems/rotate-array_1230543
#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();
    k = k % n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = arr[(i + k) % n];
    }
    return res;
}
