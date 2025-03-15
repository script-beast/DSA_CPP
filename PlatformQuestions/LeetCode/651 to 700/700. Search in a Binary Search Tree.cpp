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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root->val == val)
        return root;

    if (root == nullptr)
        return NULL;

    if (val > root->val)
        return searchBST(root->right, val);

    if (val < root->val)
        return searchBST(root->left, val);

    return NULL;
}
