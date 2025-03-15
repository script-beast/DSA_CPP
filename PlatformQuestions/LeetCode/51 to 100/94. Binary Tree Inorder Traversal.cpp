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

void slove(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    slove(root->left, ans);
    ans.push_back(root->val);
    slove(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    slove(root, ans);
    return ans;
}