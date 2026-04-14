/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// #include <string>
// #include <vector>
#include <stack>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> nodes;
        vector<vector<int>> ans;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            auto curSize = nodes.size();
            vector<int> path;
            for (int i = 0; i < curSize; i++)
            {
                auto tmpnode = nodes.front();
                path.push_back(tmpnode->val);
                nodes.pop_front();
                if (tmpnode->left)
                    nodes.push_back(tmpnode->left);
                if (tmpnode->right)
                    nodes.push_back(tmpnode->right);
            }
            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end
