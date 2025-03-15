#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int target)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (auto i : matrix)
        if (i[0] <= target && i[i.size() - 1] >= target && binarySearch(i, target))
            return true;
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;

    return 0;
}