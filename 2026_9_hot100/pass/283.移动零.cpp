/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        while (slow <= fast && fast < nums.size())
        {
            if (nums[fast] == 0)
            {
                fast++;
            }
            else
            {
                fast++;
                slow++;
            }
            if (fast < nums.size())
                nums[slow] = nums[fast];
        }
        for (int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end
