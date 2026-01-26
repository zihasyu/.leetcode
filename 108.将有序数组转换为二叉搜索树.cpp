/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBST(const vector<int> &nums, int left, int right)
    {
        // 当左边界大于右边界时，说明子数组为空，返回nullptr
        if (left > right)
        {
            return nullptr;
        }

        // 找到中间位置的索引
        int mid = left + (right - left) / 2;

        // 创建根节点
        TreeNode *root = new TreeNode(nums[mid]);

        // 递归构建左子树
        root->left = buildBST(nums, left, mid - 1);

        // 递归构建右子树
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};
// @lc code=end
