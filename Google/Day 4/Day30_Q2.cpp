/*
**********MINIMUM NUMBER OF DAYS TO DISCONNECT ISLAND**********
ou are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/12/24/land1.jpg

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:

image: https://assets.leetcode.com/uploads/2021/12/24/land2.jpg

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int no_of_conn(vector<vector<int>> &grid)
    {

        int visit[30][30] = {0};
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1 && visit[i][j] == 0)
                {
                    count++;
                    q.push({i, j});
                    visit[i][j] = 1;

                    while (!q.empty())
                    {

                        int s = q.size();

                        for (int i = 0; i < s; i++)
                        {
                            auto p = q.front();
                            q.pop();
                            int x = p.first;
                            int y = p.second;
                            if (x + 1 < grid.size() && visit[x + 1][y] == 0 && grid[x + 1][y] == 1)
                            {
                                q.push({x + 1, y});
                                visit[x + 1][y] = 1;
                            }
                            if (y + 1 < grid[0].size() && visit[x][y + 1] == 0 && grid[x][y + 1] == 1)
                            {
                                q.push({x, y + 1});
                                visit[x][y + 1] = 1;
                            }
                            if (x - 1 >= 0 && visit[x - 1][y] == 0 && grid[x - 1][y] == 1)
                            {
                                q.push({x - 1, y});
                                visit[x - 1][y] = 1;
                            }
                            if (y - 1 >= 0 && visit[x][y - 1] == 0 && grid[x][y - 1] == 1)
                            {
                                q.push({x, y - 1});
                                visit[x][y - 1] = 1;
                            }
                        }
                    }
                }

        return count;
    }

    int minDays(vector<vector<int>> &grid)
    {

        int num = no_of_conn(grid);

        if (num != 1)
            return 0;
        vector<pair<int, int>> ind;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    if (no_of_conn(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
        return 2;
    }
};