/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Map.find(nums[i]) != Map.end())
            {
                return {Map[nums[i]], i};
            }
            else
            {
                Map.insert({target - nums[i], i});
            }
        }
        return {};
    }
};
// @lc code=end
