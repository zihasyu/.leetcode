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
        if (!nums.size())
            return 0;
        map<int, bool> map;
        for (auto &tmp : nums)
        {
            map[tmp] = true;
        }
        int res = 1;
        int tmpres = 1;
        int before = INT_MAX / 2;
        for (auto &tmp : map)
        {
            if (tmp.second)
            {
                if (tmp.first - before == 1)
                {
                    tmpres++;
                    if (tmpres > res)
                    {
                        res = tmpres;
                    }
                }
                else
                {
                    tmpres = 1;
                }
                before = tmp.first;
            }
        }
        return res;
    }
};
// @lc code=end
