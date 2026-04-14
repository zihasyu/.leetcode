/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 * dp法
 * 二分贪心构建法
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::vector<int> tails;

        for (int num : nums)
        {
            // lower_bound 找到第一个不小于 num 的迭代器
            auto it = std::lower_bound(tails.begin(), tails.end(), num);

            // 如果没找到（即 num 比所有元素都大）
            if (it == tails.end())
            {
                tails.push_back(num);
            }
            // 如果找到了
            else
            {
                *it = num; // 用 num 替换掉那个更大的数
            }
        }

        return tails.size();
    }
};
// @lc code=end
