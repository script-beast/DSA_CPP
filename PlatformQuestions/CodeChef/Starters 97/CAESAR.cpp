#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f0inc(n) for (int i{0}; i < n; i++)
#define fauto(m) for (auto i : m)
typedef vector<ll> llvec;
typedef unordered_map<ll, ll> lluomp;
typedef unordered_set<ll> lluos;
typedef unordered_multiset<ll> lluoms;
typedef unordered_map<char, ll> cluomp;

#define tc    \
    ll t{0};  \
    cin >> t; \
    while (t--)

int main()
{
    cluomp m;
    char c{'a'};
    for (int i{1}; i <= 26; i++)
    {
        m[c] = i;
        c++;
    }

    cluomp rm;
    c = 'a';
    for (int i{1}; i <= 26; i++)
    {
        rm[i] = c;
        c++;
    }

    tc
    {
        int n{0};
        string s{""}, t{""}, u{""};

        cin >> n;
        cin >> s;
        cin >> t;
        cin >> u;

        ll diff = m[t[0]] - m[s[0]] ;

        string ans{""};

        f0inc(n)
        {
            int temp = m[u[i]] + diff;

            if (temp < 1)
                temp = 26 + temp;

            temp = temp % 26;

            if (temp == 0)
                temp = 26;

            ans += rm[temp];
        }

        cout << ans << endl;
    }

    return 0;
}