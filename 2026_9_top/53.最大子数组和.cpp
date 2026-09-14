/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN, min_premix = 0, premix = 0;
        for (auto num : nums)
        {
            premix += num;
            ans = max(premix - min_premix, ans);
            min_premix = min(min_premix, premix);
        }
        return ans;
    }
};
// @lc code=end
