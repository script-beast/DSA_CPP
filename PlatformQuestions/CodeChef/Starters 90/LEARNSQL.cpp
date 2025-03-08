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
    // tc
    // {
        int a1{0}, a2{0}, a3{0};
        cin >> a1 >> a2 >> a3;

        cout << (a1 + a3) * a2 << endl;
    // }

    return 0;
}