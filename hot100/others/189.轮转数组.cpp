/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// three reverse
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return;

        // 1. 处理 k > n 的情况
        k = k % n;
        if (k == 0)
            return;

        // 2. 三次反转
        // a. 整体反转
        reverse(nums.begin(), nums.end());
        // b. 反转前 k 个元素
        reverse(nums.begin(), nums.begin() + k);
        // c. 反转后 n-k 个元素
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end
