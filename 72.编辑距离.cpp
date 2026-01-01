/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        // dp[i][j] 表示 word1 的前 i 个字符转换成 word2 的前 j 个字符的最少操作数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // 初始化
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i; // 从 word1[0...i-1] 到空串，需要 i 次删除
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j; // 从空串到 word2[0...j-1]，需要 j 次插入
        }

        // 状态转移
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    // 字符相同，无需操作
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 字符不同，从替换、删除、插入中选最小成本
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j - 1], // 替换
                                       dp[i - 1][j],     // 删除
                                       dp[i][j - 1]      // 插入
                                   });
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
