/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int ansLeft = 0, ansRight = 0;
        auto n = s.size();
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l > ansRight - ansLeft)
            {
                ansRight = r;
                ansLeft = l;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l > ansRight - ansLeft)
            {
                ansRight = r;
                ansLeft = l;
            }
        }
        return s.substr(ansLeft + 1, ansRight - ansLeft - 1);
    }
};
// @lc code=end
