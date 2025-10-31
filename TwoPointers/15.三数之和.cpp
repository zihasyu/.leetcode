/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int Left = i + 1, Right = nums.size() - 1;
            while (Left < Right)
            {
                if (nums[i] + nums[Left] + nums[Right] == 0)
                {
                    res.push_back(vector<int>{nums[i], nums[Left], nums[Right]});
                    int lv = nums[Left], rv = nums[Right];
                    while (Left < Right && nums[Left] == lv)
                        ++Left;
                    while (Left < Right && nums[Right] == rv)
                        --Right;
                }
                else if (nums[i] + nums[Left] + nums[Right] < 0)
                {
                    Left++;
                }
                else
                {
                    Right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
