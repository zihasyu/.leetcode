/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        // 步骤 1: 将每个数字放到它应该在的位置
        // 数字 x 应该在下标 x-1
        for (int i = 0; i < n; ++i)
        {
            // 只处理 [1, n] 范围内的数字
            // 循环交换直到 nums[i] 不在 [1, n] 或已经在正确位置
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                // 交换 nums[i] 和 nums[nums[i]-1]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 步骤 2: 找第一个不在正确位置的数字
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        // 步骤 3: 所有 [1, n] 都在正确位置，答案是 n+1
        return n + 1;
    }
};
// @lc code=end
