/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 * dp法
 * 二分贪心构建法
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // if (nums.empty())
        // {
        //     return 0;
        // }

        // std::vector<int> tails;

        // for (int num : nums)
        // {
        //     // lower_bound 找到第一个不小于 num 的迭代器
        //     auto it = std::lower_bound(tails.begin(), tails.end(), num);

        //     // 如果没找到（即 num 比所有元素都大）
        //     if (it == tails.end())
        //     {
        //         tails.push_back(num);
        //     }
        //     // 如果找到了
        //     else
        //     {
        //         *it = num; // 用 num 替换掉那个更大的数
        //     }
        // }

        // return tails.size();
        int n = nums.size();
        if (!n)
            return 0;

        vector<int> dp(n, 1);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
