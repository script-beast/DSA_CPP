#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head)
{
    unordered_map<ListNode *, int> mp;
    while (head != NULL)
    {
        if (mp[head] > 0)
            return true;
        mp[head]++;
        head = head->next;
    }
    return false;
}
