/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        double tmp = 0, ans = 0, left = 0, right = 0;
        double kOri = k;
        while (k--)
        {
            tmp += nums[right++];
        }
        ans = tmp;
        while (left <= right && right < nums.size())
        {
            tmp -= nums[left++];
            tmp += nums[right++];
            ans = max(ans, tmp);
        }
        return ans / kOri;
    }
};
// @lc code=end
