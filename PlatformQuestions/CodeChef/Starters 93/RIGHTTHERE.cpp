#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define tc    \
    ll t{0};  \
    cin >> t; \
    while (t--)

int main()
{
    tc
    {
        int a = 0, b = 0;
        cin >> a >> b;

        string s;
        s = a >= b ? "YES" : "NO";
        cout << s << endl;
    }

    return 0;
}