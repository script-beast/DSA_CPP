#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    }
};

class LList
{
    // print      ✅
    // add first  ✅
    // add last   ✅
    // add b/w    ✅
    // del first  ✅
    // add end    ✅
    // del b/w    ✅

    // reverse    ✅
    // palindrome ✅

    Node *head = NULL;
    int len = 0;
    Node *recRevHelper(Node *temphead)
    {
        if (temphead == NULL || temphead->next == NULL)
            return temphead;

        Node *newHead = recRevHelper(temphead->next);

        temphead->next->next = temphead;
        temphead->next = NULL;

        return newHead;
    }

public:
    int size()
    {
        return len;
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

    void addFirst(int val)
    {
        Node *ptr = new Node(val);
        if (head != NULL)
        {
            ptr->next = head;
        }
        head = ptr;
        len++;
    }

    void addLast(int val)
    {
        Node *newptr = new Node(val);
        Node *ptr = head;
        if (head == NULL)
        {
            head = newptr;
            len++;
            return;
        }

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newptr;
        len++;
    }

    void addBetween(int val, int pos)
    {
        if (pos > len)
            return;

        if (pos == len)
        {
            this->addLast(val);
            return;
        }

        if (pos == 0)
        {
            this->addFirst(val);
            return;
        }

        Node *ptr = head;
        Node *newptr = new Node(val);
        pos--;

        while (pos-- && ptr->next == NULL)
            ptr = ptr->next;

        newptr->next = ptr->next;
        ptr->next = newptr;
        len++;
    }

    void delfirst()
    {
        if (head == NULL)
            return;
        Node *ptr = head;
        head = head->next;
        delete ptr;
        len--;
    }

    void dellast()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            head = NULL;
            len--;
            return;
        }
        Node *ptr = head;
        while (ptr->next->next != NULL)
            ptr = ptr->next;

        Node *delnode = ptr->next;
        ptr->next = NULL;
        delete delnode;
        len--;
    }

    void delBetween(int pos)
    {
        if (pos > len || pos < 1)
            return;

        if (pos == len)
        {
            this->dellast();
            return;
        }

        if (pos == 1)
        {
            this->delfirst();
            return;
        }

        Node *ptr = head;
        pos--, pos--;

        while (pos-- && ptr->next->next != NULL)
            ptr = ptr->next;

        Node *delNode = ptr->next;
        ptr->next = delNode->next;

        delete delNode;
        len--;
    }

    void looprev()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *prevNode = head;
        Node *currNode = head->next;

        while (currNode != NULL)
        {
            Node *nextNode = currNode->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }

        head->next = NULL;
        head = prevNode;
    }

    void recrev()
    {
        head = this->recRevHelper(head);
    }

    // bool isPalindrome() // no extra space used
    // {
    //     if (head == NULL || head->next == NULL)
    //         return true;
    //     int mid = len - (len / 2);
    //     Node *ptr = head;
    //     while (mid--)
    //         ptr = ptr->next;
    //     Node *newhead = recRevHelper(ptr);
    //     Node *firstptr = head;
    //     this->print();
    //     while (newhead != NULL)
    //     {
    //         if (firstptr->data != newhead->data)
    //             return false;
    //         firstptr = firstptr->next;
    //         newhead = newhead->next;
    //     }
    //     return true;
    // }

    bool isPalindrome()
    {
        if (head == NULL || head->next == NULL)
            return true;
        stack<int> s;

        Node *ptr = head;

        while (ptr != NULL)
        {
            s.push(ptr->data);
            ptr = ptr->next;
        }

        ptr = head;

        while (ptr != NULL)
        {
            if (s.top() != ptr->data)
                return false;
            s.pop();
            ptr = ptr->next;
        }
        return true;
    }
};

int main()
{
    LList list;

    list.print();

    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);
    list.addBetween(10, 2);
    list.addLast(5);
    list.delfirst();
    list.dellast();
    list.delBetween(6);

    list.looprev();
    list.recrev();
    cout << list.isPalindrome() << endl;

    list.print();

    return 0;
}
