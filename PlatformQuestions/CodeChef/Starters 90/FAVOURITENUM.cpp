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
        int a{0};
        cin >> a;

        bool ali = (!(a % 2) && !(a % 7));
        bool bob = ((a % 2) && !(a % 9));

        if (ali)
            cout << "Alice";
        else if (bob)
            cout << "Bob";
        else
            cout << "Charlie";
    }

    return 0;
}