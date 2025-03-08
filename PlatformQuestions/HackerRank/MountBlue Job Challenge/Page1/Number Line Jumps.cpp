#include <bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2)
{
    if(v1 == v2) return x1 == x2 ? "YES" : "NO";

    int a{0}, b{0};

    a = (x1 - x2) / (v2 - v1);
    b = (x1 - x2) % (v2 - v1);

    return (a > 0 && b == 0) ? "YES" : "NO";
}