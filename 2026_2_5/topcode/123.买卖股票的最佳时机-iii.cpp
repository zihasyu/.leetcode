/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int k = 2; // 最多交易次数

        if (n == 0 || k == 0)
        {
            return 0;
        }

        // 1. 定义三维 DP 数组: dp[天数][交易次数][是否持有]
        // 天数: n, 交易次数: k+1 (0到k), 是否持有: 2 (0或1)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));

        // 2. 初始化
        for (int j = 0; j <= k; ++j)
        {
            // 初始化第 0 天的状态
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }
        // 修正交易0次却持有的非法状态
        dp[0][0][1] = INT_MIN / 2;

        // 3. 状态转移
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                // 不持有 = max(昨天就不持有, 昨天持有今天卖)
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

                // 持有 = max(昨天就持有, 昨天不持有(且完成了j-1次交易)今天买)
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        // 4. 返回结果
        // 最终利润在最后一天，且不持有股票的状态中
        // 交易次数可以是 1 到 k 次中的任意一种
        int max_profit = 0;
        for (int j = 1; j <= k; ++j)
        {
            max_profit = max(max_profit, dp[n - 1][j][0]);
        }

        return max_profit;
    }
};
// @lc code=end
