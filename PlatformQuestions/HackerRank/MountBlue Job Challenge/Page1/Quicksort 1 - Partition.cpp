#include <bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int> arr)
{
    vector<int> result;
    int pivot = arr[0];
    vector<int> left, right;
    for (long unsigned int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    for (long unsigned int i = 0; i < left.size(); i++)
        result.push_back(left[i]);
    result.push_back(pivot);
    for (long unsigned int i = 0; i < right.size(); i++)
        result.push_back(right[i]);
    return result;
}