#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertInEmpty(int val)
{
    Node *head;
    head = new Node;
    head->data = val;

    Node *temp;
    temp = new Node;

    temp = head;

    head->next = temp;
    return head;
}

Node *insertAtBegin(Node *head, int val)
{
    if (head == NULL)
        return insertInEmpty(val);
    Node *ptr;
    ptr = new Node;
    ptr->data = val;

    Node *p;
    p = new Node;
    p = head->next;
    while (p->next != head)
        p = p->next;

    ptr->next = head;
    p->next = ptr;

    return ptr;
}

Node *insertAtEnd(Node *head, int val)
{
    if (head == NULL)
        return insertInEmpty(val);

    return insertAtBegin(head, val)->next;
}

Node *insertAfterVal(Node *head, int val, int key)
{
    if (head == NULL)
        return insertInEmpty(val);

    Node *ptr;
    ptr = new Node;
    ptr->data = val;

    Node *p;
    p = new Node;
    p = head;
    do
    {
        if (p->data == key)
            break;
        p = p->next;
    } while (p != head);

    if (p == head && p->data != key)
        return head;

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node *deleteAtBegin(Node *head)
{
    // if (head == NULL)
    //     return ;
    Node *p;
    p = new Node;
    p = head;
    do
        p = p->next;
    while (p->next != head);

    Node *ptr = head;

    p->next = ptr->next;
    head = ptr->next;

    delete ptr;

    return head;
}

Node *deleteAtEnd(Node *head)
{
    // if (head == NULL)
    //     return;

    Node *p;
    p = new Node;
    p = head;

    do
        p = p->next;
    while (p->next->next != head);

    Node *ptr = p->next;

    p->next = ptr->next;

    delete ptr;
    return head;
}

Node *deleteValue(Node *head, int val)
{
    Node *p;
    p = new Node;
    p = head;

    if (head->data == val)
        return deleteAtBegin(head);

    do
    {
        if (val == p->next->data)
            break;
        p = p->next;
    } while (p != head);

    if (p != head->next)
    {
        Node *ptr = p->next;
        p->next = ptr->next;
        delete ptr;
    }

    return head;
}

void printLL(Node *head)
{
    Node *ptr = new Node;
    ptr = head;
    if (head == NULL)
        return;
    do
    {
        cout << head->data << " -> ";
        head = head->next;
    } while (head != ptr);
    cout << endl;
}

int main()
{
    Node *head;
    head = new Node;

    head = insertInEmpty(0);
    for (int i = 1; i < 5; i++)
        head = insertAtBegin(head, i);
    printLL(head);

    head = insertAtEnd(head, -1);
    printLL(head);

    head = insertAfterVal(head, 8, 1);
    printLL(head);

    head = deleteAtBegin(head);
    printLL(head);

    head = deleteAtEnd(head);
    printLL(head);

    head = deleteValue(head, 3);
    printLL(head);

    return 0;
}