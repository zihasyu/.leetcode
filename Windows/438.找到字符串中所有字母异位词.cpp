/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> p_count(26, 0), s_count(26, 0);
        for (char c : p)
            p_count[c - 'a']++;
        for (int i = 0; i < p.size(); i++)
            s_count[s[i] - 'a']++;
        if (s_count == p_count)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            s_count[s[i] - 'a']++;
            s_count[s[i - p.size()] - 'a']--;
            if (s_count == p_count)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
// @lc code=end
