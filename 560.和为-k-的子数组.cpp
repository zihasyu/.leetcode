/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0;
        if (nums.empty())
            return ans;
        int sum = 0, left = 0, right = 0;
        while (right < nums.size())
        {
            if (sum < k)
        }
    }
};
// @lc code=end
