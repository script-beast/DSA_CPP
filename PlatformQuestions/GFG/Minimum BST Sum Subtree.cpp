#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int ans = INT_MAX;

bool check(Node *root, int min, int max)
{
    if (!root)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return check(root->left, min, root->data - 1) && check(root->right, root->data + 1, max);
}

pair<int, int> f(int target, Node *root)
{

    if (!root)
        return {0, 0};

    auto i = f(target, root->left);
    auto j = f(target, root->right);

    if (i.second + j.second + root->data == target)
    {
        if (check(root, INT_MIN, INT_MAX))
        {
            ans = min(ans, 1 + i.first + j.first);
        }
    }

    return {1 + i.first + j.first, root->data + i.second + j.second};
}

int minSubtreeSumBST(int target, Node *root)
{
    // code here
    f(target, root);
    return ans == INT_MAX ? -1 : ans;
}