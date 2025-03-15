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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *temp2 = lists[i];
        while (temp2 != NULL)
        {
            pq.push(temp2->val);
            temp2 = temp2->next;
        }
    }
    while (!pq.empty())
    {
        temp->next = new ListNode(pq.top());
        pq.pop();
        temp = temp->next;
    }
    return head->next;
}
