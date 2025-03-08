#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f0inc(n) for (int i{0}; i < n; i++)
#define fauto(m) for (auto i : m)
typedef vector<ll> llvec;
typedef unordered_map<ll, ll> lluomp;
typedef unordered_set<ll> lluos;
#define tc    \
    ll t{0};  \
    cin >> t; \
    while (t--)

int main()
{
    tc
    {
        int n{0}, k{0};
        cin >> n >> k;

        string ans{""};
        ans = n%2 ? n/2 < k ? "YES" : "NO" : n/2 <= k ? "YES" : "NO";

        cout << ans << "\n";
    }

    return 0;
}