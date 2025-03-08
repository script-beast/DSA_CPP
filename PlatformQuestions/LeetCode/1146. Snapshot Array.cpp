#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
    vector<vector<pair<int, int>>> arr;
    int snap_id{0};

public:
    SnapshotArray(int length)
    {
        arr.resize(length);
    }

    void set(int index, int val)
    {
        arr[index].push_back({snap_id, val});
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return it == arr[index].begin() ? 0 : prev(it)->second;
    }
};