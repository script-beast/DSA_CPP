#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f0inc(n) for (int i{0}; i < n; i++)
#define fauto(m) for (auto i : m)
typedef vector<ll> llvec;
typedef vector<string> strvec;
typedef unordered_map<ll, ll> lluomp;
typedef unordered_set<ll> lluos;
typedef unordered_map<string, ll> lsuomp;
typedef unordered_set<string> stuos;
#define tc    \
    ll t{0};  \
    cin >> t; \
    while (t--)

int main()
{
    ll n{0};
    cin >> n;

    strvec v(n);
    f0inc(n) cin >> v[i];

    stuos s;
    string ans{""};

    for (ll i{n - 1}; i >= 0; i--)
    {
        if (s.find(v[i]) == s.end())
        {
            int len = v[i].length();
            ans += v[i][len - 2];
            ans += v[i][len - 1];
            s.insert(v[i]);
        }
    }

    cout << ans << endl;

    return 0;
}