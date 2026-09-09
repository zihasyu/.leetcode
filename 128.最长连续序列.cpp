/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        int ans = 0, tmp = 1;
        for (auto s : st)
        {
            if (st.find(s + 1) != st.end())
            {
                tmp++;
                ans = max(ans, tmp);
            }
            else
            {
                tmp = 1;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
// @lc code=end
