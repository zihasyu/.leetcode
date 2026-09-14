/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int h = height.size();
        vector<int> LeftPremix, RightPremix(h, 0);
        int left = 0, right = 0;
        for (int i = 0; i < h; i++)
        {
            left = max(left, height[i]);
            LeftPremix.push_back(left);
        }
        for (int i = h - 1; i >= 0; i--)
        {
            right = max(right, height[i]);
            RightPremix[i] = right;
        }
        int ans = 0;
        for (int i = 0; i < h; i++)
        {
            ans += min(LeftPremix[i], RightPremix[i]) - height[i];
        }
        return ans;
    }
};
// @lc code=end
