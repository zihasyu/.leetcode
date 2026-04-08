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
        int i = 0, j = height.size() - 1;
        int res = 0;
        while (j > i)
        {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] >= height[j])
            {
                while (j > i && height[i] >= height[j])
                {
                    j--;
                    res = max(res, min(height[i], height[j]) * (j - i));
                }
            }
            else
            {
                while (j > i && height[i] < height[j])
                {
                    i++;
                    res = max(res, min(height[i], height[j]) * (j - i));
                }
            }
        }
        return res;
    }
};
// @lc code=end
