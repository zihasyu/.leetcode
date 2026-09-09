/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size(), n = matrix[0].size();
        // 从右上角开始
        int i = 0, j = n - 1;

        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                // 当前元素太大，向左移动
                j--;
            }
            else
            {
                // 当前元素太小，向下移动
                i++;
            }
        }

        return false;
    }
};
// @lc code=end
