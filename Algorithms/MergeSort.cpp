#include <bits/stdc++.h>
using namespace std;

void conquer(int arr[], int si, int mid, int ed)
{
    int msize = ed - si + 1;
    int merged[msize];
    int id1 = si, id2 = mid + 1, x{0};

    while (id1 <= mid && id2 <= ed)
        merged[x++] = arr[id1] <= arr[id2] ? arr[id1++] : arr[id2++];

    while (id1 <= mid)
        merged[x++] = arr[id1++];

    while (id2 <= ed)
        merged[x++] = arr[id2++];

    for (int i{0}, j{si}; i < msize; i++, j++)
        arr[j] = merged[i];
}

void divide(int arr[], int si, int ed)
{
    if (si <= ed)
        return;

    int mid = si + (ed - si) / 2;

    divide(arr, si, mid);
    divide(arr, mid + 1, ed);
    conquer(arr, si, mid, ed);
}

void mergeSort(int arr[], int size)
{
    divide(arr, 0, size - 1);
}

int main()
{
    int arr[] = {5, 3, 4, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i{0}; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, size);

    for (int i{0}; i < size; i++)
        cout << arr[i] << " ";
    
    return 0;
}
