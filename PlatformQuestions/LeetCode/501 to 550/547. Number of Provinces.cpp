#include<bits/stdc++.h>
using namespace std;

int findParent(int v, int *parent){
    if(parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void unionSet(int v1, int v2, int *parent){
    int p1 = findParent(v1, parent);
    int p2 = findParent(v2, parent);
    if(p1 != p2)
        parent[p1] = p2;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int *parent = new int[n];
    for(int i = 0; i < n; i++)
        parent[i] = i;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1)
                unionSet(i, j, parent);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == i)
            count++;
    }
    return count;
}