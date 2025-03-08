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
        int p{0}, q{0}, r{0}, s{0};
        cin >> p >> q >> r >> s;

        string ans{""};

        if (p > q + r + s || q > p + r + s || r > p + q + s || s > p + q + r)
            ans = "YES";
        else
            ans = "NO";
        cout << ans << "\n";
    }

    return 0;
}