/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        vector<int> Big, Small, equal;
        int random = nums[rand() % nums.size()];
        for (auto num : nums)
        {
            if (num < random)
            {
                Small.push_back(num);
            }
            else if (num > random)
            {
                Big.push_back(num);
            }
            else
            {
                equal.push_back(num);
            }
        }
        if (Big.size() >= k)
        {
            return findKthLargest(Big, k);
        }
        else if (Big.size() + equal.size() >= k)
        {
            return random;
        }
        else
        {
            return findKthLargest(Small, k - (Big.size() + equal.size()));
        }
    }
};
// @lc code=end
