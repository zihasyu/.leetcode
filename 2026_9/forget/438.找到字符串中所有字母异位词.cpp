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
        vector<int> P(26, 0), S(26, 0);
        for (auto c : p)
        {
            P[c - 'a']++;
        }
        int m = p.size(), n = s.size();
        if (n < m)
            return {};
        for (int i = 0; i < m; i++)
        {
            S[s[i] - 'a']++;
        }
        vector<int> ans;

        for (int i = 0; i <= n - m; i++)
        {
            if (S == P)
                ans.push_back(i);

            S[s[i] - 'a']--;
            if (i + m < n)
                S[s[i + m] - 'a']++;
        }
        return ans;
    }
};
// @lc code=end
