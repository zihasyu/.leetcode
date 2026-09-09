/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), tmpSize = 0, right = 0;
        int ans = INT_MAX;
        for (int left = 0; left < n; left++)
        {
            while (right < n && tmpSize < target)
            {
                tmpSize += nums[right++];
            }
            if (tmpSize >= target)
                ans = min(right - left, ans);
            tmpSize -= nums[left];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
