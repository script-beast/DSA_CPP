#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void helper(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    if (root->key == key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if (root->key > key)
    {
        suc = root;
        helper(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        helper(root->right, pre, suc, key);
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    helper(root, pre, suc, key);
}