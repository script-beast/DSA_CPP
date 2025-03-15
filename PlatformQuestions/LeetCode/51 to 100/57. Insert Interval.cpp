#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> merge(vector<vector<int>> &interval)
// {
//     vector<vector<int>> result;
//     if (interval.size() == 0)
//         return result;
//     sort(interval.begin(), interval.end());
//     result.push_back(interval[0]);
//     int j = 0;
//     for (int i = 1; i < interval.size(); i++)
//     {
//         if (result[j][1] >= interval[i][0])
//             result[j][1] = max(result[j][1], interval[i][1]);
//         else
//         {
//             j++;
//             result.push_back(interval[i]);
//         }
//     }
//     return result;
// }
// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// {
//     intervals.push_back(newInterval);
//     vector<vector<int>> ans;
//     ans = merge(intervals);
//     return ans;
// }

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    vector<int> temp = newInterval;

    for (auto one : intervals)
    {
        if (one[1] < temp[0])
            ans.push_back(one);

        else if (one[0] > temp[1])
        {
            ans.push_back(temp);
            temp = one;
        }
        else
        {
            temp[0] = min(temp[0], one[0]);
            temp[1] = max(temp[1], one[1]);
        }
    }
    ans.push_back(temp);

    return ans;
}
