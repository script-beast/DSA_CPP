#include <bits/stdc++.h>
using namespace std;

void calDistance(int node, vector<int> &edges, vector<int> &ans, vector<bool> &visited)
{
    visited[node] = true;
    int nextNode = edges[node];
    if (nextNode != -1 && visited[nextNode] == false)
    {
        ans[nextNode] = ans[node] + 1;
        calDistance(nextNode, edges, ans, visited);
    }
}
int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();
    vector<int> disNode1(n), disNode2(n);
    vector<bool> visNode1(n), visNode2(n);
    calDistance(node1, edges, disNode1, visNode1);
    calDistance(node2, edges, disNode2, visNode2);
    int ans = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (visNode1[i] == true && visNode2[i] == true && minDist > max(disNode1[i], disNode2[i]))
        {
            minDist = max(disNode1[i], disNode2[i]);
            ans = i;
        }
    }
    return ans;
}