/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            auto tmp = (right - left) * min(height[right], height[left]);
            ans = max(ans, tmp);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return ans;
    }
};
// @lc code=end
