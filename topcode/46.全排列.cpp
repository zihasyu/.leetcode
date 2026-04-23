/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * 排列题需要一个visited数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<bool> visited;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;

            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums);
            visited[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        visited.resize(n);
        dfs(nums);
        return ans;
    }
};
// @lc code=end
