/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * 前缀和的要点是：当前前缀和要比最小前缀和快一步
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int min_prefix_sum = 0;
        int current_prefix_sum = 0;
        for (auto num : nums)
        {
            current_prefix_sum += num;
            ans = max(ans, current_prefix_sum - min_prefix_sum);
            min_prefix_sum = min(current_prefix_sum, min_prefix_sum);
        }
        return ans;
    }
};
// @lc code=end
