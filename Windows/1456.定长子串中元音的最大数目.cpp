/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool IsYuan(char a)
    {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            return true;
        return false;
    }

    int maxVowels(string s, int k)
    {
        if (s.size() < k)
            return 0;
        int ans = 0, left = 0, right = 0, tmp = 0, tmpsize = k;
        while (tmpsize--)
        {
            tmp += IsYuan(s[right++]);
        }
        ans = tmp;
        while (left <= right && right < s.size())
        {
            tmp -= IsYuan(s[left++]);
            tmp += IsYuan(s[right++]);
            ans = max(ans, tmp);
        }
        return ans;
    }
};
// @lc code=end
