#include <bits/stdc++.h>
using namespace std;

int getTotalX(vector<int> a, vector<int> b)
{
    int count = 0;
    for (int i = a[a.size() - 1]; i <= b[0]; i++)
    {
        bool flag = true;
        for (long unsigned int j = 0; j < a.size(); j++)
        {
            if (i % a[j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (long unsigned int j = 0; j < b.size(); j++)
            {
                if (b[j] % i != 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            count++;
    }
    return count;
}