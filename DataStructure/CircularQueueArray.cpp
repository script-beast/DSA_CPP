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

    
};

int main()
{
    Queue list = Queue(10);
    list.print();

    if (1 == 1 == 1)
        cout << "HI";
}