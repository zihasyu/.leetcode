/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    vector<int> ans;
    void Loop(TreeNode *Father)
    {
        if (Father->left)
        {
            Loop(Father->left);
        }
        ans.push_back(Father->val);
        if (Father->right)
        {
            Loop(Father->right);
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            Loop(root);
        }
        return ans;
    }
};
// @lc code=end
