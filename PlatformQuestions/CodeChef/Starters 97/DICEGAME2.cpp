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
        int a1{0}, a2{0}, a3{0}, b1{0}, b2{0}, b3{0};

        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

        int a{0}, b{0};

        // find the smallest number in a1, a2, a3

        if (a1 <= a2 && a1 <= a3)
            a = a1;
        else if (a2 <= a1 && a2 <= a3)
            a = a2;
        else
            a = a3;

        // find the smallest number in b1, b2, b3

        if (b1 <= b2 && b1 <= b3)
            b = b1;
        else if (b2 <= b1 && b2 <= b3)
            b = b2;
        else
            b = b3;

        string ans = a1+a2+a3 - a == b1+b2+b3 - b ? "Tie" : a1+a2+a3 - a > b1+b2+b3 - b ? "Alice" : "Bob";

        cout << ans << endl;
        
    }

    return 0;
}