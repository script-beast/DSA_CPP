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

bool isapfree(llvec a)
{
    for (int i{0}; i < a.size() - 2; i++)
        for (int j{i + 1}; j < a.size() - 1; j++)
            for (int k{j + 1}; k < a.size(); k++)
                if (a[i] + a[k] == 2 * a[j])
                    return false;

    return true;
}

//optimised

// bool isapfree(llvec a)
// {
//     lluomp m;
//     for (int i{0}; i < a.size(); i++)
//         m[a[i]]++;

//     for (auto i : m)
//         if (i.second > 2)
//             return false;

//     return true;
// }

int main()
{
    tc
    {
        int n{0};
        cin >> n;

        llvec a(n);
        f0inc(n) cin >> a[i];

        if (isapfree(a))
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}