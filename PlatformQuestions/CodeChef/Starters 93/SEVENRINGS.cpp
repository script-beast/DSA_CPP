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
        string code, number, ans;
        cin >> code >> number;
        ans = (code + number)[0] != '0' && (code + number).length() == 5 ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}