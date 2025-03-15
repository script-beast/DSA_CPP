#include <bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    int n = words.size();
    vector<int> ref(26, -1);
    for (int i = 0; i < order.size(); i++)
        ref[order[i] - 'a'] = i;
    
    for (int i = 0; i < (n - 1); i++)
    {
        int a = words[i].size(), b = words[i + 1].size();
        int k = 0, j = 0, flg = 0;
        while (k < a and j < b)
        {
            if (ref[words[i][k] - 'a'] > ref[words[i + 1][j] - 'a'])
                return false;
            if (ref[words[i][k] - 'a'] < ref[words[i + 1][j] - 'a'])
            {
                flg = 1;
                break;
            }
            k++;
            j++;
        }
        if (flg)
            continue;
        else
        {
            if (a > b)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}