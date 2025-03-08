#include <bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b)
{
    vector<int> result(2, 0);
    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
            result[0]++;
        else if (a[i] < b[i])
            result[1]++;
    }
    return result;
}