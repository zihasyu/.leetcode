/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0, sum = 0, minLen = INT_MAX;
        while (right < nums.size() || sum >= target)
        {
            if (sum < target)
            {
                sum += nums[right];
                right++;
            }
            else if (sum >= target)
            {
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
// @lc code=end
