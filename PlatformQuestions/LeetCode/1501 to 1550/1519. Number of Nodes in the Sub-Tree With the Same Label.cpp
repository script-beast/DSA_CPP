#include <bits/stdc++.h>
using namespace std;

vector<int> utl(unordered_map<int, vector<int>> &adj, int cur, int prev, string &labels, vector<int> &result)
{
    vector<int> ans(26, 0);

    for (int i{0}; i < adj[cur].size(); i++)
    {
        if (!result[adj[cur][i]])
        {
            vector<int> temp = utl(adj, adj[cur][i], cur, labels, result);

            transform(ans.begin(), ans.end(), temp.begin(), temp.end(), plus<int>());
        }
    }

    result[cur] = ans[labels[cur] - 'a']++;

    return ans;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    unordered_map<int, vector<int>> adj;

    for (vector<int> &e : edges)
        adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

    vector<int> result(n, 0);
    utl(adj, 0, -1, labels, result);

    return result;
}