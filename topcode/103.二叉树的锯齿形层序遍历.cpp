/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;
class Solution
{

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;

        deque<TreeNode *> q;
        q.push_back(root);
        bool IsReverse = false;
        while (!q.empty())
        {
            auto size = q.size();
            vector<int> path;
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                path.push_back(it->val);
                q.pop_front();
                if (it->left)
                    q.push_back(it->left);
                if (it->right)
                    q.push_back(it->right);
            }
            if (IsReverse)
            {
                reverse(path.begin(), path.end());
                IsReverse = false;
            }
            else
                IsReverse = true;

            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end
