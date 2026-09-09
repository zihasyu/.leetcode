/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1;       // 指向 nums1 有效部分的末尾
        int p2 = n - 1;       // 指向 nums2 的末尾
        int tail = m + n - 1; // 指向 nums1 的最末尾
        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] > nums2[p2])
            {
                nums1[tail] = nums1[p1];
                p1--;
            }
            else
            {
                nums1[tail] = nums2[p2];
                p2--;
            }
            tail--;
        }
        while (p2 >= 0)
        {
            nums1[tail] = nums2[p2];
            p2--;
            tail--;
        }
    }
};
// @lc code=end
