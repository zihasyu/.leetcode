/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right)
        {
            // 从左到右遍历上边
            for (int j = left; j <= right; j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // 从上到下遍历右边
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 从右到左遍历下边（需要检查是否还有行）
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // 从下到上遍历左边（需要检查是否还有列）
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
// @lc code=end
