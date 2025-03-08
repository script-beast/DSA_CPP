// https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}