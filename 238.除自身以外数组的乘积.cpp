/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n);

        // 步骤 1: 计算每个位置左边的乘积
        // answer[i] = nums[0] * nums[1] * ... * nums[i-1]
        answer[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // 步骤 2: 从右到左遍历，乘以右边的乘积
        // 同时计算右边的乘积
        int right = 1; // right 表示 nums[i+1] * nums[i+2] * ... * nums[n-1]
        for (int i = n - 1; i >= 0; --i)
        {
            // answer[i] 现在等于 left[i] * right
            answer[i] = answer[i] * right;
            // 更新右边乘积，为下一轮迭代准备
            right *= nums[i];
        }

        return answer;
    }
};
// @lc code=end
