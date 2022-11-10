#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> a;

    a.push('a');
    a.push('b');
    a.push('c');
    a.push('d');
    a.push('e');
    a.push('f');
    a.push('g');

    cout << a.top();

    a.pop();
    a.pop();

    cout << a.top();
}