#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int dfs(unordered_map<int, vector<int>> &adj, int src, unordered_map<int, bool> &vis, int k)
{
    if (k == 0)
        return 0;
    int ans = src;
    vis[src] = true;
    for (int a : adj[src])
        if (vis[a] == false)
            ans += dfs(adj, a, vis, k - 1);

    return ans;
}

void travarse(Node *root, unordered_map<int, vector<int>> &adj)
{
    if (!root)
        return;
    if (root->left)
        adj[root->data].push_back(root->left->data), adj[root->left->data].push_back(root->data);
    if (root->right)
        adj[root->data].push_back(root->right->data), adj[root->right->data].push_back(root->data);
    travarse(root->left, adj);
    travarse(root->right, adj);
}

int ladoos(Node *root, int home, int k)
{
    unordered_map<int, vector<int>> adj;
    travarse(root, adj);
    unordered_map<int, bool> vis;
    return dfs(adj, home, vis, k + 1);
}