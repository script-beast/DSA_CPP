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

class solution
{
public:
    vector<TreeNode *> func(int start, int end)
    {
        vector<TreeNode *> ans;

        if (start > end)
        {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = func(start, i - 1);
            vector<TreeNode *> right = func(i + 1, end);

            for (TreeNode *l : left)
            {
                for (TreeNode *r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>();

        return func(1, n);
    }
};