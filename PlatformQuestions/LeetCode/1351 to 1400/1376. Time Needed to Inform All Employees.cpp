#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &adj, vector<int> &informTime, int src)
    {
        int ans = 0;
        for (int i = 0; i < adj[src].size(); i++)
            ans = max(ans, dfs(adj, informTime, adj[src][i]));

        return ans + informTime[src];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < manager.size(); i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);

        return dfs(adj, informTime, headID);
    }
};