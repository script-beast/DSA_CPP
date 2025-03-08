#include <bits/stdc++.h>
using namespace std;

int minimizeIt(vector<int> A, int K)
{
    sort(A.begin(), A.end());
    int n = A.size();

    int ans = A[n - 1] - A[0];
    int small = A[0] + K, big = A[n - 1] - K;
    int currMin = A[0] + K, currMax = A[n - 1] - K;

    for (int i = 0; i < n - 1; i++)
    {
        currMin = min(small, A[i + 1] - K);
        currMax = max(big, A[i] + K);
        if (currMin < 0)
            continue;
        ans = min(ans, currMax - currMin);
    }
}