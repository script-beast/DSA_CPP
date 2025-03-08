#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f0inc(n) for (int i{0}; i < n; i++)
#define fauto(m) for (auto i : m)
typedef vector<ll> llvec;
typedef unordered_map<ll, ll> lluomp;
typedef unordered_map<string, ll> llusmp;
typedef unordered_set<ll> lluos;
#define tc    \
    ll t{0};  \
    cin >> t; \
    while (t--)

int main()
{
    tc
    {
        ll n{0}, m{0}, h{0};
        cin >> n >> m >> h;

        llvec a(n), b(m);

        f0inc(n) cin >> a[i];
        f0inc(m) cin >> b[i];

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        ll ans{0};

        ll i{0}, j{0};

        for (; i < n && j < m; i++, j++)
            ans += min(a[i], b[j] * h);

        cout << ans << endl;
    }

    return 0;
}