/*
**********COUNT SUBTREES QITH  MAX DISTANCES BETWEEN CITIES**********
There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.

A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.

Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.

Notice that the distance between the two cities is the number of edges in the path between them.



Example 1:

image: https://assets.leetcode.com/uploads/2020/09/21/p1.png

Input: n = 4, edges = [[1,2],[2,3],[2,4]]
Output: [3,4,0]
Explanation:
The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
No subtree has two nodes where the max distance between them is 3.
Example 2:

Input: n = 2, edges = [[1,2]]
Output: [1]
Example 3:

Input: n = 3, edges = [[1,2],[2,3]]
Output: [2,1]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mp[15] = {};
    int find(vector<int> &nums, int i)
    {
        if (nums[i] == -1)
            return i;
        else
            return nums[i] = find(nums, nums[i]);
    }
    void union_(vector<int> &nums, int x, int y)
    {
        int i = find(nums, x), j = find(nums, y);
        if (i != j)
        {
            if (i < j)
                nums[j] = i;
            else
                nums[i] = j;
        }
    }
    int findmaxdist(vector<vector<int>> &nums, vector<bool> &arr, int vis, int in, int &sum)
    {
        arr[in] = 1;
        int re = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums[in].size(); ++i)
        {
            int j = nums[in][i];
            if (bool(vis & (1 << j)) && arr[j] == 0)
            {
                int k = findmaxdist(nums, arr, vis, j, sum);
                re = max(re, k);
                q.push(k);
                if (q.size() > 2)
                    q.pop();
            }
        }
        int p = 0;
        while (!q.empty())
        {
            p += q.top();
            q.pop();
        }

        sum = max(sum, p);
        return re + 1;
    }
    void count(vector<vector<int>> g, int vis, int n)
    {
        vector<int> nums(n, -1);
        int l = 0;
        for (int i = 0; i < n; ++i)
            if ((vis & (1 << i)))
            {
                l = i;
                for (int j = 0; j < g[i].size(); ++j)
                {
                    int k = g[i][j];
                    if ((vis & (1 << k)))
                        union_(nums, i, k);
                }
            }
        int re = 0;
        for (int i = 0; i < n; ++i)
            if ((vis & (1 << i)))
                if (nums[i] == -1)
                    re++;
        if (re != 1)
            return;
        vector<bool> arr(n, 0);
        int k = 0;
        findmaxdist(g, arr, vis, l, k);
        mp[k]++;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &arr)
    {
        vector<vector<int>> nums(n);
        for (int i = 0; i < arr.size(); ++i)
        {
            nums[arr[i][0] - 1].push_back(arr[i][1] - 1);
            nums[arr[i][1] - 1].push_back(arr[i][0] - 1);
        }
        int last = (1 << n);
        for (int i = 1; i < last; ++i)
            count(nums, i, n);
        vector<int> re;
        for (int i = 1; i < n; ++i)
            re.push_back(mp[i]);
        return re;
    }
};