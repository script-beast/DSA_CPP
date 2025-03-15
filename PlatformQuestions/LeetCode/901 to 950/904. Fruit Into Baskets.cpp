#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> basket;
    int i = 0, j = 0, ans = 0;
    while (j < fruits.size())
    {
        basket[fruits[j]]++;
        if (basket.size() <= 2)
            ans = max(ans, j - i + 1);
        else
        {
            basket[fruits[i]]--;
            if (basket[fruits[i]] == 0)
                basket.erase(fruits[i]);
            i++;
        }
        j++;
    }

    return ans;
}