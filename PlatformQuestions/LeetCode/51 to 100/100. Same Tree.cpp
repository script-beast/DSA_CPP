#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == q && p == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    bool left = isSameTree(p->left, q->left);
    if (!left)
        return false;
    bool right = isSameTree(p->right, q->right);
    if (!right)
        return false;
    bool same = p->val == q->val;

    return left && right && same;
}