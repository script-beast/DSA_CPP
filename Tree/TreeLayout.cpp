#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int a)
    {
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void addNode(int data)
    {
        Node *newNode = new Node(data);

        if (root == nullptr)
            root = newNode;
        else
        {
            Node *focusNode = root;
            Node *parent;
            while (true)
            {
                parent = focusNode;
                if (data < focusNode->data)
                {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void preOrderTraversal(Node *focusNode)
    {
        if (focusNode != nullptr)
        {
            preOrderTraversal(focusNode->left);
            cout << focusNode->data << " ";
            preOrderTraversal(focusNode->right);
        }
    }
};

Node *root()
{
    BinaryTree tree;

    tree.addNode(50);
    tree.addNode(25);
    tree.addNode(75);
    tree.addNode(12);
    tree.addNode(37);
    tree.addNode(43);
    tree.addNode(30);

    return tree.root;
}