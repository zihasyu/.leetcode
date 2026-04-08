/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> res;
        res.reserve(m * n);
        while (left <= right && top <= bottom)
        {
            // 上
            for (int j = left; j <= right; ++j)
                res.push_back(matrix[top][j]);
            ++top;
            // 右
            for (int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            --right;
            // 下
            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    res.push_back(matrix[bottom][j]);
                --bottom;
            }
            // 左
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    res.push_back(matrix[i][left]);
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end
