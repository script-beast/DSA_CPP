#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int count{0};
    for (auto &row : grid)
        for (auto &col : row)
            if (col < 0)
                count++;
    return count;
}

// optimized
