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

class stackLL
{
    Node *head = NULL;

public:
    void print()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void push(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }

        Node *p = head;
        while (p->next != NULL)
            p = p->next;

        Node *ptr = new Node(val);
        p->next = ptr;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node *p = head;
        if (p->next == NULL)
        {
            delete p;
            head = NULL;
            return;
        }
        while (p->next->next != NULL)
            p = p->next;
        delete p->next;
        p->next = NULL;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        return p->data;
    }

    int peek(int pos)
    {
        int i = pos;
        Node *ptr;
        ptr = head;
        while (ptr != NULL && --pos)
            ptr = ptr->next;

        if (ptr == NULL)
            return -1;

        if (!pos)
            return ptr->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    stackLL s;
    s.push(10);
    cout << s.top() << endl;
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    cout << s.top() << endl;
    cout << s.peek(9) << endl;
    // s.print();
    // s.pop();
    // s.pop();
    // cout << s.top() << endl;
    cout << s.isEmpty() << endl;
}