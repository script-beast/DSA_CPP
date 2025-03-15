#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int count = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if (coins >= costs[i])
        {
            coins -= costs[i];
            count++;
        }
        else
            break;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        int coins;
        cin >> coins;
        vector<int> costs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }
        int result = maxIceCream(costs, coins);
        cout << result << " ";
    }
    return 0;
}