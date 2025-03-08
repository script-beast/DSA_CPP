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
        ll n{0};
        llusmp m;
        cin >> n;

        for (ll i{0}; i < n; i++)
        {
            string s{""};
            cin >> s;
            m[s]++;
        }

        ll ans{0};

        ans += m["O"];
        ans += max(m["A"], m["B"]);
        ans += m["AB"];

        cout << ans << endl;
    }

    return 0;
}