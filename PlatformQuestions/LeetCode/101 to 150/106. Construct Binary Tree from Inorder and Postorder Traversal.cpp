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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0)
        return nullptr;

    int rootVal = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootVal);

    int k = 0;
    for (; k < inorder.size(); k++)
        if (inorder[k] == rootVal)
            break;

    vector<int> leftInorder(inorder.begin(), inorder.begin() + k);
    vector<int> rightInorder(inorder.begin() + k + 1, inorder.end());

    vector<int> leftPostorder(postorder.begin(), postorder.begin() + k);
    vector<int> rightPostorder(postorder.begin() + k, postorder.end() - 1);

    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);

    return root;
}