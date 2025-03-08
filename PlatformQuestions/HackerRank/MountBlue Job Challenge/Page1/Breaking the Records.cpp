#include <bits/stdc++.h>
using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
    int min = scores[0], max = scores[0], minCount = 0, maxCount = 0;
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i] < min)
        {
            min = scores[i];
            minCount++;
        }
        else if (scores[i] > max)
        {
            max = scores[i];
            maxCount++;
        }
    }
    return {maxCount, minCount};
}