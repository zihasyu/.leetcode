/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = height[0], suffix[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto MinFix = min(prefix[i], suffix[i]);
            ans += MinFix - height[i];
        }
        return ans;
    }
};
// @lc code=end
