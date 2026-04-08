/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // 步骤1: 记录原始首行首列是否有0
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0)
                firstColZero = true;

        // 步骤2: 用首行首列做标记
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                                }

        // 步骤3: 根据标记清零内部
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // 步骤4: 最后处理首行首列本身
        if (firstRowZero)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
// @lc code=end
