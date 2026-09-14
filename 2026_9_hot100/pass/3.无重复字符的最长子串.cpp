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
        unordered_set<char> Set;
        int left = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (Set.find(s[i]) == Set.end())
            {
                Set.insert(s[i]);
            }
            else
            {
                while (Set.find(s[i]) != Set.end())
                {
                    Set.erase(s[left]);
                    left++;
                }
                Set.insert(s[i]);
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
// @lc code=end
