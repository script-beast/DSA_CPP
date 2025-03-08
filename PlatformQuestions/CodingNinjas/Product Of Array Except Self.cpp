#include <bits/stdc++.h>
using namespace std;

int *getProductArrayExceptSelf(int *arr, int n)
{
    if (n == 1 || n == 0)
    {
        int *ans = new int[1];
        ans[0] = 1;
        return ans;
    }
    int mod = 1e9 + 7;
    int *ans = new int[n];
    unsigned long long int product = 1;

    for (int i = 0; i < n; i++)
        product = (product * arr[i]) % mod;
    
    for (int i = 0; i < n; i++)
        ans[i] = arr[i] == 0 ? product : (product/arr[i]);

    return ans;
}