/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}};
        stack<char> st;
        for (char ch : s)
        {
            // 如果是右括号
            if (pairs.count(ch))
            {
                // 栈为空，或栈顶不匹配
                if (st.empty() || st.top() != pairs[ch])
                {
                    return false;
                }
                // 匹配成功，弹出栈顶
                st.pop();
            }
            // 如果是左括号
            else
            {
                st.push(ch);
            }
        }

        // 遍历结束后，栈必须为空才有效
        return st.empty();
    }
};
// @lc code=end
