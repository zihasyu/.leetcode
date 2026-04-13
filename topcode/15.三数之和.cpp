/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 这题重点在去重逻辑，双指针去重时需要加上left<right的边界，不然会越界
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[i] > 0)
                {
                    right--;
                }
                else if (nums[left] + nums[right] + nums[i] < 0)
                {
                    left++;
                }
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
