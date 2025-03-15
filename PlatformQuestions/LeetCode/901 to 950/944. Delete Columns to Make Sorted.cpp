#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<string> &strs, int col)
{
    for (int i = 0; i < strs.size() - 1; i++)
        if (strs[i][col] > strs[i + 1][col])
            return false;
    return true;
}

int minDeletionSize(vector<string> &strs)
{
    int res = 0;
    for (int i = 0; i < strs[0].size(); i++)
        if (!isSorted(strs, i))
            res++;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    cout << minDeletionSize(strs) << endl;
    return 0;
}