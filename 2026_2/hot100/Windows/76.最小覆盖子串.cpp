/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int need[128] = {0}, window[128] = {0};
        int needValid = 0;

        for (char c : t)
        {
            if (need[c] == 0)
                needValid++;
            need[c]++;
        }

        int valid = 0, left = 0, ansLeft = -1, ansLen = INT_MAX;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;
            if (window[c] == need[c])
                valid++;

            while (valid == needValid)
            {
                if (right - left + 1 < ansLen)
                {
                    ansLen = right - left + 1;
                    ansLeft = left;
                }

                char cLeft = s[left];
                window[cLeft]--;
                if (window[cLeft] < need[cLeft])
                    valid--;
                left++;
            }
        }

        return ansLeft == -1 ? "" : s.substr(ansLeft, ansLen);
    }
};
// @lc code=end
