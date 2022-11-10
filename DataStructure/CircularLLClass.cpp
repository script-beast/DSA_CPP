#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class CircularLL
{
    Node *head = NULL;

public:
    void print()
    {
        Node *p = head;
        if (head == NULL)
            return;
        do
        {
            cout << p->data << " -> ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }

    void insertInEmpty(int val)
    {
        Node *p = new Node(val);
        p->next = p;
        head = p;
    }

    void insertInBegin(int val)
    {
        Node *ptr = new Node(val);
        Node *p = head;

        do
            p = p->next;
        while (p->next != head);

        ptr->next = head;
        p->next = ptr;
        head = ptr;
    }

    void insertInEnd(int val)
    {
        Node *ptr = new Node(val);
        Node *p = head;

        do
            p = p->next;
        while (p->next != head);

        ptr->next = head;
        p->next = ptr;
        head = ptr->next;
    }

    void insertAfterVal(int val, int key)
    {
        Node *ptr = new Node(val);
        Node *p = head;

        do
        {
            if (p->data == key)
                break;
            p = p->next;
        } while (p != head);

        if (p == head && p->data != key)
            return;

        ptr->next = p->next;
        p->next = ptr;
    }

    void deleteAtBegin()
    {
        Node *p = head;
        do
            p = p->next;
        while (p->next != head);

        Node *ptr = head;

        p->next = head->next;
        head = ptr->next;
        delete ptr;
    }

    void deleteAtEnd()
    {
        Node *p = head;
        do
            p = p->next;
        while (p->next->next != head);

        Node *ptr = p->next;

        p->next = head;

        delete ptr;
    }

    void deleteValue(int key)
    {
        Node *p = head;
        do
        {
            if (p->next->data == key)
                break;
            p = p->next;
        } while (p != head);

        Node *ptr = p->next;
        p->next = ptr->next;
        delete ptr;
    }
};

int main()
{
    CircularLL list;

    list.insertInEmpty(10);
    list.insertInBegin(20);
    list.insertInBegin(30);
    list.insertInBegin(40);
    list.insertInBegin(50);
    list.insertInEnd(0);
    list.insertAfterVal(15, 10);
    list.deleteAtBegin();
    list.deleteAtEnd();
    list.deleteValue(10);

    list.print();
}