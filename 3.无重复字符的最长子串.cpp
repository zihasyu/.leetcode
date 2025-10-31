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
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.size())
        {
            char c = s[right];
            map[c]++;
            while (map[c] > 1)
            {
                char d = s[left];
                map[d]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end
