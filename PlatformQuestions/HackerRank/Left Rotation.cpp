#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    int i{0}, n{0};

    n = arr.size();
    i = d;

    vector<int> ans;

    for (int i{d}; i < n; i++)
        ans.push_back(arr[i]);

    for (int i{0}; i < d; i++)
        ans.push_back(arr[i]);

    return ans;
}

int main()
{
    int n{0}, d{0};
    cin >> n >> d;

    vector<int> arr(n);

    for (int i{0}; i < n; i++)
        cin >> arr[i];

    vector<int> ans = rotateLeft(d, arr);

    for (int i : arr)
        cout << i << " ";

    cout << endl;
    return 0;
}