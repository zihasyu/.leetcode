/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// the question requires us to use only constant-level memory overhead, so we can't use unorderedmap to finish indexing. Meanwhile, we can't modify this vector from input, so ...
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 1. 寻找相遇点 (Floyd 判圈算法)
        int slow = 0;
        int fast = 0;
        do
        {
            // slow 走一步
            slow = nums[slow];
            // fast 走两步
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 2. 寻找环的入口
        // 将一个指针重置到起点
        int ptr1 = 0;
        int ptr2 = slow; // 或者 fast，因为它们在同一点
        while (ptr1 != ptr2)
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        // 两个指针相遇的地方就是环的入口，其值就是重复的数字
        return ptr1;
    }
};
// @lc code=end
