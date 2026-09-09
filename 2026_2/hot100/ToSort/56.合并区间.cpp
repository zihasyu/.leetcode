/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// I want to open a map for '1-n' and finally check this map for ans;
// No!!!
// the standard situation is sort+greedy;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return {};
        }

        // 1. 按区间的左端点排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]); // 先放入第一个区间

        // 2. 遍历并合并
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> &last = ans.back();      // 结果中的最后一个区间
            vector<int> &current = intervals[i]; // 当前要处理的区间

            // 如果当前区间的左端点 <= 结果中最后一个区间的右端点，说明有重叠
            if (current[0] <= last[1])
            {
                // 合并区间，更新右端点为两者中的最大值
                last[1] = max(last[1], current[1]);
            }
            else
            {
                // 没有重叠，直接将当前区间加入结果
                ans.push_back(current);
            }
        }

        return ans;
    }
};
// @lc code=end
