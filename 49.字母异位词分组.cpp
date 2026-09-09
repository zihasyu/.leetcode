/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> ans;
        for (auto s : strs)
        {
            auto tmp = s;
            sort(tmp.begin(), tmp.end());
            ans[tmp].push_back(s);
        }
        vector<vector<string>> ans2;
        for (auto &m : ans)
        {
            ans2.push_back(m.second);
        }
        return ans2;
    }
};
// @lc code=end
