#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &children, string &s, int root, int &res)
{
    int first_max = 0;
    int second_max = 0;
    char ch = s[root];
    for (int child : children[root])
    {
        int len = helper(children, s, child, res);
        if (s[child] == ch)
            continue;

        {
            if (first_max < len)
            {
                second_max = first_max;
                first_max = len;
            }
            else if (second_max < len)
            {
                second_max = len;
            }
        }
    }
    res = max(res, first_max + second_max + 1);
    return first_max + 1;
}

int longestPath(vector<int> &parent, string s)
{
    int res = 0;
    int n = parent.size();
    vector<vector<int>> children(n);
    for (int i = 1; i < parent.size(); i++)
    {

        children[parent[i]].push_back(i);
    }

    helper(children, s, 0, res);
    return res;
}

int main()
{
    int n{0};
    cin >> n;
    vector<int> parent(n);
    for (int i{0}; i < n; i++)
        cin >> parent[i];

    string s{""};
    cin >> s;

    cout << longestPath(parent, s);
    return 0;
}
