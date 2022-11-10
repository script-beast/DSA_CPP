#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node *insertAtBegin(Node *head, int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->next = head;
    return temp;
}

Node *insertAfter(Node *head, int val, int pos)
{
    Node *ptr = new Node;
    ptr = head;
    int i = 1;
    while (i++ < pos && head->next != NULL)
        head = head->next;

    Node *add;
    add = new Node;

    add->data = val;
    add->next = head->next;
    head->next = add;

    return ptr;
}

Node *insertBefore(Node *head, int val, int pos)
{
    Node *ptr = new Node;
    ptr = head;
    int i = 1;
    while (i++ < pos - 1 && head->next != NULL)
        head = head->next;

    Node *add = new Node;
    add->data = val;
    add->next = head->next;
    head->next = add;

    return ptr;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *ptr = new Node;
    ptr = head;

    while (head->next != NULL)
        head = head->next;

    Node *add = new Node;
    add->data = val;
    add->next = NULL;
    head->next = add;

    return ptr;
}

Node *insertAfterNodeValue(Node *head, int val, int nod)
{
    Node *ptr = new Node;
    ptr = head;

    while (head->next != NULL)
    {
        if (head->data == nod)
            break;
        head = head->next;
    }

    Node *add = new Node;
    add->data = val;
    add->next = head->next;
    head->next = add;

    return ptr;
}

Node *deleteAtBegin(Node *head)
{
    Node *temp = new Node;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteInBetween(Node *head, int pos)
{
    Node *ptr = new Node;
    ptr = head;
    int i = 1;
    while (i++ < pos - 1 && head->next != NULL)
        head = head->next;

    Node *temp = new Node;
    temp = head->next;
    head->next = temp->next;
    free(temp);
    // cout << head->data;

    return ptr;
}

Node *deleteAtEnd(Node *head)
{
    Node *ptr = new Node;
    ptr = head;
    while (head->next->next != NULL)
        head = head->next;

    Node *p = new Node;
    p = head->next->next;
    head->next = NULL;
    free(p);
    return ptr;
}

Node *deleteWithNodeValue(Node *head, int nod)
{
    Node *ptr = new Node;
    ptr = head;
    while (head->next != NULL)
    {
        if (head->next->data == nod)
            break;
        head = head->next;
    }

    Node *pt = new Node;
    pt = head->next;
    head->next = pt->next;
    free(pt);

    return ptr;
}

int main()
{
    Node *head, *start;
    head = new Node;
    start = new Node;

    head->data = 0;
    head->next = NULL;

    start = head;

    for (int i = 1; i < 5; i++)
    {
        Node *tem;
        tem = new Node;
        tem->data = i;
        tem->next = NULL;

        head->next = tem;
        head = head->next;
    }

    printLL(start);

    start = insertAtBegin(start, 7);
    printLL(start);

    start = insertAfter(start, 6, 2);
    printLL(start);

    start = insertBefore(start, 7, 4);
    printLL(start);

    start = insertAtEnd(start, 9);
    printLL(start);

    start = insertAfterNodeValue(start, 12, 2);
    printLL(start);

    start = deleteAtBegin(start);
    printLL(start);

    start = deleteInBetween(start, 5);
    printLL(start);

    start = deleteAtEnd(start);
    printLL(start);

    start = deleteWithNodeValue(start, 12);
    printLL(start);

    return 0;
}