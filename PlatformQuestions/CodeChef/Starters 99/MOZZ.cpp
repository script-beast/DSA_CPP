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
        ll x{0}, y{0}, r{0};
        cin >> x >> y >> r;
        float d = ((r / 30) + x) / y;
        cout << ceil(d) << endl;
    }
    return 0;
}