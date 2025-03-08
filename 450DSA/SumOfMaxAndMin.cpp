// https://www.naukri.com/code360/problems/sum-of-max-and-min_1081476
#include <bits/stdc++.h>
using namespace std;

int sumOfMaxMin(int arr[], int n)
{
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }
    return max + min;
}