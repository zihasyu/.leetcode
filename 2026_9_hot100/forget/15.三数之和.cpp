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
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            auto target = nums[i] * -1;
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                auto ValueLeft = nums[left], ValueRight = nums[right];
                if (ValueLeft + ValueRight == target)
                {
                    ans.push_back({nums[i], ValueLeft, ValueRight});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (ValueLeft + ValueRight < target)
                {
                    left++;
                }
                else
                    right--;
            }
        }
        return ans;
    }
};
// @lc code=end
