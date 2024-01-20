/*
**********ERECT THE FENCE**********
You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/04/24/erect2-plane.jpg

Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
Example 2:

image: https://assets.leetcode.com/uploads/2021/04/24/erect1-plane.jpg

Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ori(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        return (c[1] - b[1]) * (b[0] - a[0]) < (b[1] - a[1]) * (c[0] - b[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = trees.size();
        if (n <= 3)
            return trees;
        sort(trees.begin(), trees.end());
        vector<int> vis(n, 0), uh, lh;
        for (int i = 0; i < n; i++)
        {
            int szu = uh.size();
            while (szu >= 2 and ori(trees[uh[szu - 2]], trees[uh[szu - 1]], trees[i]))
                vis[uh[szu - 1]]--, szu--, uh.pop_back();
            uh.push_back(i);
            vis[i]++;
            int szl = lh.size();
            while (szl >= 2 and ori(trees[lh[szl - 2]], trees[lh[szl - 1]], trees[n - i - 1]))
                vis[lh[szl - 1]]--, szl--, lh.pop_back();
            lh.push_back(n - i - 1);
            vis[n - i - 1]++;
        }
        vector<vector<int>> ch;
        for (int i = 0; i < n; i++)
            if (vis[i])
                ch.push_back(trees[i]);
        return ch;
    }
};