#include <bits/stdc++.h>
using namespace std;

class stackArray
{
    int n = 100;
    int arr[100];
    int rear = -1;

public:
    void push(int v)
    {
        if (rear == n)
        {

            cout << "Overflow";
            return;
        }

        arr[++rear] = v;
    }

    void pop()
    {
        if (rear == -1)
        {
            cout << "Underflow";
            return;
        }

        --rear;
    }

    int top()
    {
        return arr[rear];
    }

    bool isEmpty()
    {
        return rear == -1;
    }

    bool isFull()
    {
        return rear == n;
    }
};

int main()
{
    stackArray a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);

    cout << a.top() << endl;

    cout << a.isEmpty() << endl;

    a.pop();
    a.pop();

    cout << a.top();

    return 0;
}
