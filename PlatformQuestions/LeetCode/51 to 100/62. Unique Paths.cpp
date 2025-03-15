#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}