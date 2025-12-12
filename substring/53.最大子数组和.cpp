/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * kadane算法
 * [53] 最大子数组和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int maxEndingHere = nums[0]; // 以当前位置结尾的最大和
        int maxSoFar = nums[0];      // 全局最大和
        for (int i = 1; i < nums.size(); i++)
        {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
// @lc code=end
