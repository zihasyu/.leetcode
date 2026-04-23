/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid])
            {
                // 左半部分有序 [left, mid]
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1; // target 在左半部分
                }
                else
                {
                    left = mid + 1; // target 在右半部分
                }
            }
            else
            {
                // 右半部分有序 [mid, right]
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1; // target 在右半部分
                }
                else
                {
                    right = mid - 1; // target 在左半部分
                }
            }
        }
        return -1;
    }
};
// @lc code=end
