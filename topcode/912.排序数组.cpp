/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 * 1.堆
 * 2.快排
 * 3.排序数组
 */
// #include <queue>
// #include <iostream>
// using namespace std;
// @lc code=start
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         priority_queue<int, vector<int>, greater<int>> MaxHeap;
//         for (auto num : nums)
//             MaxHeap.push(num);
//         vector<int> ans;
//         while (!MaxHeap.empty())
//         {
//             ans.push_back(MaxHeap.top());
//             MaxHeap.pop();
//         }
//         return ans;
//     }
// };

#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        int pivot = left + rand() % (right - left + 1);
        int pivotValue = nums[pivot];
        swap(nums[left], nums[pivot]);
        pivot = left;

        int LeftIndex = left + 1, RightIndex = right;
        while (LeftIndex <= RightIndex)
        {
            while (LeftIndex <= RightIndex && nums[LeftIndex] < pivotValue)
            {
                LeftIndex++;
            }
            while (LeftIndex <= RightIndex && nums[RightIndex] > pivotValue)
            {
                RightIndex--;
            }
            if (RightIndex >= LeftIndex)
            {
                swap(nums[RightIndex], nums[LeftIndex]);
                RightIndex--;
                LeftIndex++;
            }
        }
        swap(nums[RightIndex], nums[pivot]);
        quickSort(nums, left, RightIndex - 1);
        quickSort(nums, RightIndex + 1, right);
    }
};
// @lc code=end
