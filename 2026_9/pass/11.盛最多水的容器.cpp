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
        int ans = 0, tmp = 0;
        while (left < right)
        {
            ans = max(min(height[left], height[right]) * (right - left), ans);
            if (height[left] > height[right])
            {
                right--;
            }
            else
                left++;
        }
        return ans;
    }
};
// @lc code=end
