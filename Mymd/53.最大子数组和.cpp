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
        int MinPrefixSum = 0;
        int currentPrefixSum = 0;
        for (auto num : nums)
        {
            currentPrefixSum += num;
            ans = max(ans, currentPrefixSum - MinPrefixSum);
            MinPrefixSum = min(MinPrefixSum, currentPrefixSum);
        }
        return ans;
    }
};
// @lc code=end
