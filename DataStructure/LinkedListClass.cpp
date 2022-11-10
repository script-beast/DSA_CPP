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

class LinkedList
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

  void insertAtBegin(int val)
  {
    Node *ptr = new Node(val);

    if (head == NULL)
    {
      head = ptr;
      return;
    }

    ptr->next = head;
    head = ptr;
  }

  void insertAfter(int val, int pos)
  {
    Node *newnode = new Node(val);
    Node *ptr = head;

    int i = 1;
    while (i++ < pos && ptr->next != NULL)
      ptr = ptr->next;

    newnode->next = ptr->next;
    ptr->next = newnode;
  }

  void insertAtEnd(int val)
  {
    Node *ptr = new Node(val);
    Node *p = head;

    while (p->next != NULL)
      p = p->next;

    p->next = ptr;
  }

  void deleteAtBegin()
  {
    Node *ptr = head;
    head = ptr->next;
    delete ptr;
  }

  void deleteIndex(int pos)
  {
    Node *p = head;
    int i = 0;
    while (++i < pos - 2 && p->next != NULL)
      p = p->next;

    if (i != pos - 2)
      return;

    Node *ptr = p->next;
    p->next = ptr->next;
    delete ptr;
  }

  void deleteAtEnd()
  {
    Node *p = head;
    while (p->next->next != NULL)
      p = p->next;

    Node *ptr = p->next;
    p->next = ptr->next;
    delete ptr;
  }

  void deleteValue(int val)
  {
    Node *p = head;
    while (p != NULL)
    {
      if (p->next->data == val)
        break;
      p = p->next;
    }

    if (p == NULL)
      return;

    Node *ptr = p->next;
    p->next = ptr->next;
    delete ptr;
  }
};

int main()
{
  LinkedList list;

  list.insertAtBegin(10);
  list.insertAtBegin(12);
  list.insertAfter(11, 1);
  list.insertAtEnd(13);
  list.print();
  // list.deleteAtBegin();
  // list.deleteIndex(9);
  // list.deleteAtEnd();
  list.deleteValue(1);
  list.print();

  return 0;
}