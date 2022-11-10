#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
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

void printReverseLL(Node *head)
{
    while (head->next != NULL)
        head = head->next;
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->prev;
    }
    cout << endl;
}

Node *InsertAtBegin(Node *head, int val)
{
    Node *ptr;
    ptr = new Node;
    ptr->data = val;
    ptr->prev = NULL;
    if (head == NULL)
        ptr->next = NULL;
    else
    {
        ptr->next = head;
        head->prev = ptr;
    }

    return ptr;
}

Node *InsertAtEnd(Node *head, int val)
{
    Node *p;
    p = head;

    while (p->next != NULL)
        p = p->next;

    Node *ptr;
    ptr = new Node;

    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;

    return head;
}

Node *InsertAfterNode(Node *head, int val, int key)
{
    Node *p;
    p = head;
    while (p != NULL)
    {
        if (p->data == key)
            break;
        p = p->next;
    }

    if (p == NULL)
        return head;

    if (p->next == NULL)
        return InsertAtEnd(head, val);

    Node *ptr;
    ptr = new Node;

    ptr->data = val;
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    ptr->next->prev = ptr;

    return head;
}

Node *InsertBeforeNode(Node *head, int val, int key)
{
    Node *p;
    p = head;

    if (head->data == key)
        return InsertAtBegin(head, val);

    while (p != NULL)
    {
        if (p->next->data == key)
            break;
        p = p->next;
    }

    if (p == NULL)
        return head;

    Node *ptr;
    ptr = new Node;

    ptr->data = val;
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    ptr->next->prev = ptr;

    return head;
}

Node *DeleteBegin(Node *head)
{
    Node *p;
    p = head;

    p = p->next;
    p->prev = NULL;

    delete head;
    return p;
}

Node *DeleteEnd(Node *head)
{
    Node *p;
    p = head;
    while (p->next != NULL)
        p = p->next;

    Node *pre;
    pre = p->prev;
    pre->next = NULL;

    delete p;
    return head;
}

Node *DeleteMiddle(Node *head, int key)
{
    if (head->data == key)
        return DeleteBegin(head);
    Node *p;
    p = head;

    while (p->next != NULL)
    {
        if (p->data == key)
            break;
        p = p->next;
    }

    // if (p->data == key)

    if (p->next == NULL)
        return head;

    Node *ptr, *pre, *suc;
    ptr = p;
    pre = p->prev;
    suc = p->next;

    pre->next = ptr->next;
    suc->prev = ptr->prev;

    delete ptr;

    return head;
}

int main()
{
    Node *head;
    head = new Node;
    head = NULL;

    head = InsertAtBegin(head, 10);
    head = InsertAtBegin(head, 9);
    head = InsertAtBegin(head, 8);
    head = InsertAtBegin(head, 7);
    printLL(head);

    head = InsertAfterNode(head, 11, 10);
    printLL(head);

    head = InsertAfterNode(head, 16, 10);
    printLL(head);

    head = InsertBeforeNode(head, 6, 7);
    printLL(head);

    head = InsertAtEnd(head, 12);
    printLL(head);

    // printReverseLL(head);

    head = DeleteBegin(head);
    printLL(head);

    head = DeleteMiddle(head, 9);
    printLL(head);

    head = DeleteEnd(head);
    printLL(head);

    printReverseLL(head);
}