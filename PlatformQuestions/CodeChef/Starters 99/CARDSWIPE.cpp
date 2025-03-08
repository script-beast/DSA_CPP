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

        llvec v(n);
        f0inc(n) cin >> v[i];

        lluos s;
        long unsigned int maxperson{0};

        f0inc(n)
        {
            if (s.find(v[i]) == s.end())
            {
                s.insert(v[i]);
                maxperson = max(maxperson, s.size());
            }
            else
                s.erase(v[i]);
        }

        cout << maxperson << endl;
    }

    return 0;
}