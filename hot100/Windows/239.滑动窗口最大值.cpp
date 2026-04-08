/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// 这题的难度在于，前最大值滑出滑窗时，你不知道是否有重复值或者次大值、
// 想象成nums[]是以恶搞index，那么用单调队列存下标的方式来做历史排序。
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty() || k == 0)
        {
            return {};
        }

        vector<int> ans;
        // deque 中存储的是数组元素的下标
        deque<int> q;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 1. 保证队列单调递减：
            // 当新元素 nums[i] 进来时，把前面比它小的都从队尾移除
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            // 将当前元素下标加入队尾
            q.push_back(i);

            // 2. 移除越界队头：
            // 判断队头元素是否已经滑出窗口
            if (q.front() <= i - k)
            {
                q.pop_front();
            }

            // 3. 记录结果：
            // 当窗口形成后 (i >= k-1)，队头就是当前窗口的最大值
            if (i >= k - 1)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end
