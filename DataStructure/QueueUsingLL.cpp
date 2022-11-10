#include <bits/stdc++.h>
using namespace std;

// Add    ✅
// remove ✅
// peek   ✅

struct Node
{
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class Queue
{
    Node *head, *rear;

public:
    Queue()
    {
        this->head = NULL;
        this->rear = NULL;
    }

    void print()
    {
        Node *ptr = head;

        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }

        cout << "NULL" << endl;
    }

    void add(int val)
    {
        Node *nw = new Node(val);
        if (head == NULL)
        {
            head = rear = nw;
            return;
        }

        rear->next = nw;
        rear = rear->next;
    }

    int peek()
    {
        return head->data;
    }

    void remove()
    {
        if (head == rear)
        {
            head = rear = NULL;
            return;
        }
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }
};

int main()
{
    Queue list = Queue();

    list.print();

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << list.peek() << endl;
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.remove();

    list.print();

    return 0;
}
