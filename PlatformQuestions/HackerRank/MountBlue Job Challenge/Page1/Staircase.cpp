#include <bits/stdc++.h>
using namespace std;

void staircase(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "#";
        cout << endl;
    }
}