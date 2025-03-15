#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    int curmax, mainmax, curmin, mainmin, tsum{0};
    curmax = mainmax = -1e8;
    curmin = mainmin = 1e8;
    for (auto i : nums)
    {
        // for max
        curmax = max(i, curmax + i);
        mainmax = max(mainmax, curmax);

        // for min
        curmin = min(i, curmin + i);
        mainmin = min(mainmin, curmin);

        // total sum
        tsum += i;
    }

    if (mainmax < 0)
        return mainmax;
    return max(mainmax, tsum - mainmin);
}