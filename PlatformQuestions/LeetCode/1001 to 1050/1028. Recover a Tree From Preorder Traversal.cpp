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

class Solution
{
public:
    // TreeNode *recoverFromPreorder(string traversal)
    // {
    //     int n = traversal.size();
    //     stack<TreeNode *> st;
    //     for (int i = 0; i < n;)
    //     {
    //         int level = 0;
    //         while (i < n && traversal[i] == '-')
    //         {
    //             level++;
    //             i++;
    //         }
    //         int val = 0;
    //         while (i < n && traversal[i] != '-')
    //         {
    //             val = val * 10 + (traversal[i] - '0');
    //             i++;
    //         }
    //         TreeNode *node = new TreeNode(val);
    //         while (st.size() > level)
    //             st.pop();
    //         if (!st.empty())
    //         {
    //             if (!st.top()->left)
    //                 st.top()->left = node;
    //             else
    //                 st.top()->right = node;
    //         }
    //         st.push(node);
    //     }
    //     while (st.size() > 1)
    //         st.pop();
    //     return st.top();
    // }

    TreeNode *recRecoverFromPreorder(string &traversal, int &i, int level)
    {
        int n = traversal.size();
        int j = i; 
        while (j < n && traversal[j] == '-')
            j++;
        if (j - i != level)
            return nullptr;
        i = j;
        int val = 0;
        while (j < n && traversal[j] != '-')
        {
            val = val * 10 + (traversal[j] - '0');
            j++;
        }
        TreeNode *node = new TreeNode(val);
        node->left = recRecoverFromPreorder(traversal, j, level + 1);
        node->right = recRecoverFromPreorder(traversal, j, level + 1);
        return node;
    }

    TreeNode *recoverFromPreorder(string traversal) {
        int i = 0;
        return recRecoverFromPreorder(traversal, i, 0);
    }
};