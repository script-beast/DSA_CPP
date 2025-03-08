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
        ll n{0}, m{0}, k{0}, mx{0};

        cin >> n >> m >> k;

        f0inc(n) cin >> mx;

        string ans{0};

        ans = m - mx <= (k - 1) ? "YES" : "NO";

        cout << ans << endl;
    }

    return 0;
}