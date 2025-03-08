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
        ll n{0};
        cin >> n;
        ll sum{0};

        llvec v(n);
        f0inc(n)
        {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end());

        f0inc(n)
        {
            cout << sum << " ";
            sum -= v[i];
        }

        cout << endl;
    }

    return 0;
}