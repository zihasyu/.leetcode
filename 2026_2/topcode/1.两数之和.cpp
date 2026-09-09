/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 纯粹的map
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Map;
        int index = 0;
        for (auto num : nums)
        {
            if (Map.find(target - num) == Map.end())
            {
                Map[num] = index++;
            }
            else
            {
                return {Map[target - num], index};
            }
        }
        return {};
    }
};
// @lc code=end
