/*
**********MAP OF HIGHEST PEAK**********
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:

image:  https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82045-am.png

Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:

image: https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82050-am.png

Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<int> delx = {0, -1, 0, 1};
        vector<int> dely = {-1, 0, 1, 0};

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            for (int i = 0; i < 4; i++)
            {
                int newx = x + delx[i];
                int newy = y + dely[i];

                if (isValid(newx, newy, isWater) && vis[newx][newy] == 0)
                {
                    ans[newx][newy] = ans[x][y] + 1;
                    q.push({newx, newy});
                    vis[newx][newy] = 1;
                }
            }
        }

        return ans;
    }
};