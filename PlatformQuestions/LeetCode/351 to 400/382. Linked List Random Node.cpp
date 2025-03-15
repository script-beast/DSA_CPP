#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    int len;
    vector<int> v;

public:
    Solution(ListNode *head)
    {
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        len = v.size();
    }

    int getRandom()
    {
        return v[rand() % len];
    }
};