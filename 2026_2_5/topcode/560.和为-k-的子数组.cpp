/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 * 前缀和即可，但是记得要给0一个天然的1
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefix;
        int curSize = 0;
        int ans = 0;
        prefix[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            curSize += nums[i];
            if (prefix.find(curSize - k) != prefix.end())
                ans += prefix[curSize - k];
            prefix[curSize]++;
        }
        return ans;
    }
};
// @lc code=end
