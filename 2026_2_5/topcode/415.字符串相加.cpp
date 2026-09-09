/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0; // 进位

        while (i >= 0 || j >= 0 || carry)
        {
            int n1 = i >= 0 ? num1[i--] - '0' : 0;
            int n2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = n1 + n2 + carry;
            res.push_back('0' + (sum % 10)); // 当前位
            carry = sum / 10;                // 新进位
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
