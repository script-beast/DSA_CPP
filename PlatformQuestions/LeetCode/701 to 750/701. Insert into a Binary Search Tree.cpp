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

TreeNode *insertIntoBST(TreeNode *root, int value)
{
    if (!root)
        return new TreeNode(value);

    if (value > root->val)
        root->right = insertIntoBST(root->right, value);

    else if (value < root->val)
        root->left = insertIntoBST(root->left, value);

    return root;
}