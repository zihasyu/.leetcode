/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int right = numbers.size() - 1;
        for (int left = 0; left < right; left++)
        {
            while (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
        }
        return {};
    }
};
// @lc code=end
