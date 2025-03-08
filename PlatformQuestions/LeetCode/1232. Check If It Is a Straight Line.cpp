#include<bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if(n == 2)
        return true;
    int x1 = coordinates[0][0], y1 = coordinates[0][1];
    int x2 = coordinates[1][0], y2 = coordinates[1][1];
    int dx = x2 - x1, dy = y2 - y1;
    for(int i = 2; i < n; i++){
        int x = coordinates[i][0], y = coordinates[i][1];
        if(dx * (y - y2) != dy * (x - x2))
            return false;
    }
    return true;
}