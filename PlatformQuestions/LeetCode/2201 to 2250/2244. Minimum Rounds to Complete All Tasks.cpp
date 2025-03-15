#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < tasks.size(); i++)
        mp[tasks[i]]++;

    int rounds = 0;
    for (auto [task, val] : mp)
    {
        if (val == 1)
            return -1;
        if (val % 3 == 0)
            rounds += val / 3;
        else
            rounds += val / 3 + 1;
    }

    return rounds;
}

int main()
{
    int n;
    cin >> n;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i];
    cout << minimumRounds(tasks) << endl;
    return 0;
}