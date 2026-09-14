/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> Map(128, 0);
        int left = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (Map[s[i]] == 0)
            {
                ans = max(ans, i - left + 1);
            }
            else
            {
                while (Map[s[i]] > 0)
                {
                    Map[s[left++]] -= 1;
                }
                ans = max(ans, i - left + 1);
            }
            Map[s[i]]++;
        }
        return ans;
    }
};
// @lc code=end
