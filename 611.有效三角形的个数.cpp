/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = n - 1; i >= 2; --i)
        {
            int left = 0;
            int right = i - 1;

            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    count += (right - left);
                    right--; // 尝试一个更小的 b
                }
                else
                {
                    left++;
                }
            }
        }

        return count;
    }
};
// @lc code=end
