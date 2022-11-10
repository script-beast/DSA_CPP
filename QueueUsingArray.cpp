#include <bits/stdc++.h>
using namespace std;

// Add    ✅
// remove ✅
// peek   ✅

class Queue
{
    int arr[100];
    int size;
    int rear;

public:
    Queue(int val)
    {
        size = val;
        rear = -1;
    }

    bool isEmpty()
    {
        return rear == -1;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void add(int val)
    {
        if (isFull())
            return;

        arr[++rear] = val;
    }

    void remove()
    {
        if (isEmpty())
            return;

        for (int i = 1; i <= rear; i++)
            arr[i - 1] = arr[i];

        rear--;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    void print()
    {
        for (int i{0}; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    Queue list = Queue(5);

    list.add(10);
    list.add(11);
    list.add(12);
    list.add(13);

    list.remove();
    list.remove();
    list.remove();
    list.remove();

    list.print();
}