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
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = target - nums[i];
            if (map.find(a) != map.end())
            {
                res.push_back(map[a]);
                res.push_back(i);
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};
// @lc code=end
