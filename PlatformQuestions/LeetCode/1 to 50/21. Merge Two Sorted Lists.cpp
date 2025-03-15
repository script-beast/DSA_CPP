#include <bits/stdc++.h>
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1)
        p->next = list1;
    if (list2)
        p->next = list2;
    return head->next;
}