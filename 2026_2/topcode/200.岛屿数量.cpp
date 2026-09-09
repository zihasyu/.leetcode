/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        if (x >= 0 && y < grid[0].size() && x < grid.size() && y >= 0 && grid[x][y] == '1')
        {
            grid[x][y] = '2';
            dfs(x + 1, y, grid);
            dfs(x, y + 1, grid);
            dfs(x, y - 1, grid);
            dfs(x - 1, y, grid);
        }
        else
            return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
