/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
class Solution
{
private:
    int maxDiameter = 0;

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 递归计算左右子树的深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // 经过当前节点的路径长度 = 左深度 + 右深度
        // 用它来更新全局最大直径
        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        // 返回当前节点的深度 = 左右子树深度的较大值 + 1
        return std::max(leftDepth, rightDepth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return maxDiameter;
    }
};
// @lc code=end
