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
        string s{""};

        cin >> n;
        cin >> s;

        // count any positive number of right parenthesis between two colons

        int count{0};

        bool flag{false};

        f0inc(n)
        {
            if (s[i] == ':')
            {

                int j = i + 1;

                while (j < n && s[j] != '(')
                {
                    if (s[j] == ':')
                    {
                        if (j - i - 1 > 0)
                        {
                            cout << j << " " << i << endl;
                            count++;
                        }
                        break;
                    }
                    j++;
                }

                i = j - 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}