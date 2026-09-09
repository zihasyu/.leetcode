/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    if (i - 2 >= 0)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                else
                {
                    int leftIndex = i - dp[i - 1] - 1;
                    if (leftIndex >= 0 && s[leftIndex] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (leftIndex > 0)
                            dp[i] += dp[leftIndex - 1];
                    }
                    else
                        dp[i] = 0;
                }
            }
        }
        return ranges::max(dp);
    }
};
// @lc code=end
