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
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // 初始化前缀和为0的计数为1
        int prefixSum = 0;
        for (int num : nums)
        {
            prefix  Sum += num;
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end())
            {
                ans += prefixSumCount[prefixSum - k];
            }
            prefixSumCount[prefixSum]++;
        }
        return ans;
    }
};
// @lc code=end
