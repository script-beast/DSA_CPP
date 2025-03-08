#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n == 0 || k == 0) return ans;
        vector<int> v;
        dfs(n, k, 1, v, ans);
        return ans;
    }
    void dfs(int n, int k, int pos, vector<int>& v, vector<vector<int>>& ans){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        for(int i = pos; i <= n; i++){
            v.push_back(i);
            dfs(n, k, i + 1, v, ans);
            v.pop_back();
        }
    }
};