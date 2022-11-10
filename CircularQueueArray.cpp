#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int arr[100];
    int size;
    int front;
    int rear;

public:
    Queue(int val)
    {
        this->size = val;
        this->front = -1;
        this->rear = -1;
    }

    void print()
    {
        for (int i{front}; i != rear; i = ((i + 1) % size))
            cout << arr[i] << " ";
        cout << endl;
    }

    bool isEmpty()
    {
        return rear == -1;
    }

    bool isFull()
    {
        return front == rear != 0;
    }

    // void add(int val)
    // {
    //     if (isFull())
    //         return;

    //     if (front == rear == -1)
    //     {
    //         front = rear = 0;
    //         arr[front] = val;
    //         return;
    //     }

    //     rear = (rear + 1) % size;
    //     arr[rear] = val;
    // }

    // void remove()
    // {
    //     if (isEmpty())
    //         return;

    //     if ()
    // }
};

int main()
{
    Queue list = Queue(10);
    list.print();

    if (1 == 1 == 1)
        cout << "HI";
}