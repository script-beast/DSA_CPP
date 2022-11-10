#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLL
{
    Node *head = NULL;

public:
    void printLL()
    {
        Node *p;
        p = head;
        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << endl;
    }

    void printReverseLL()
    {
        Node *p;
        p = head;

        while (p->next != NULL)
            p = p->next;

        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->prev;
        }
        cout << endl;
    }

    void InsertAtBegin(int val)
    {
        Node *ptr;
        ptr = new Node(val);
        if (head == NULL)
        {
            head = ptr;
            return;
        }

        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }

    void InsertAtEnd(int val)
    {
        Node *p, *ptr;
        ptr = new Node(val);
        p = head;

        while (p->next != NULL)
            p = p->next;

        ptr->prev = p;
        p->next = ptr;
    }

    void InsertAfterNode(int val, int key)
    {
        Node *p;
        p = head;
        while (p->next != NULL)
        {
            if (p->data == key)
                break;
            p = p->next;
        }
        if (p->data == key && p->next == NULL)
        {
            InsertAtEnd(val);
            return;
        }

        if (p->next == NULL)
            return;

        Node *ptr;
        ptr = new Node(val);

        ptr->prev = p;
        ptr->next = p->next;
        p->next->prev = ptr;
        p->next = ptr;
    }

    void InsertBeforeNode(int val, int key)
    {
        if (head->data == key)
        {
            InsertAtBegin(val);
            return;
        }

        Node *p;
        p = head;
        while (p->next != NULL)
        {
            if (p->data == key)
                break;
            p = p->next;
        }

        if (p->next == NULL && p->data != key)
            return;

        Node *ptr;
        ptr = new Node(val);

        ptr->next = p;
        ptr->prev = p->prev;
        p->prev->next = ptr;
        p->prev = ptr;
    }

    void DeleteBegin()
    {
        if (head == NULL)
            return;
        Node *p = head;
        head = head->next;
        head->prev = NULL;
        delete p;
    }

    void DeleteEnd()
    {
        if (head == NULL)
            return;
        Node *p;
        p = head;

        while (p->next != NULL)
            p = p->next;

        p->prev->next = NULL;

        delete p;
    }

    void DeleteMiddle(int key)
    {
        if (head->data == key)
        {
            DeleteBegin();
            return;
        }

        Node *p;
        p = head;

        while (p->next != NULL)
        {
            if (p->data == key)
                break;
            p = p->next;
        }

        if (p->next == NULL && p->data != key)
            return;

        if (p->next == NULL && p->data == key)
        {
            DeleteEnd();
            return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }
};

int main()
{
    DoublyLL list, list2;

    list.InsertAtBegin(10);
    list.InsertAtBegin(9);
    list.InsertAtBegin(8);
    list.InsertAtBegin(7);
    list.InsertAtEnd(11);
    list.InsertAfterNode(12, 9);
    list.InsertBeforeNode(2, 11);
    list.DeleteBegin();
    list.DeleteEnd();
    list.DeleteMiddle(2);
    list.printLL();
    list.printReverseLL();

    list2 = list;

    list2.printLL();
}