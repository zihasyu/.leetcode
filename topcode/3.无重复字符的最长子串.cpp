/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 1. 滑窗的话，用for来控制右指针，用for中的while控制左指针。
 * 2. 用数组代替无序map可以节约空间
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, left = 0, tmpSize = 0;
        vector<int> Map(128, 0);
        for (int right = 0; right < s.size(); right++)
        {
            if (Map[s[right]] == 0)
            {
                Map[s[right]]++;
                tmpSize++;
                ans = max(ans, tmpSize);
            }
            else
            {
                while (Map[s[right]] != 0)
                {
                    Map[s[left++]]--;
                    tmpSize--;
                }
                Map[s[right]]++;
                tmpSize++;
                ans = max(ans, tmpSize);
            }
        }
        return ans;
    }
};
// @lc code=end
