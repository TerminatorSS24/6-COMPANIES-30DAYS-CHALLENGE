/*
**********You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

Solution(int[][] rects) Initializes the object with the given rectangles rects.
int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.
 

Example 1:

image: https://assets.leetcode.com/uploads/2021/07/24/lc-pickrandomrec.jpg

Input
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
Output
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> &r;
    int v[101]{}, i{};

public:
    Solution(vector<vector<int>> &r) : r(r)
    {
        for (const auto &r : r)
            v[i + 1] = v[i] + (r[2] - r[0] + 1) * (r[3] - r[1] + 1), ++i;
    }

    vector<int> pick()
    {
        auto k =
            upper_bound(begin(v), begin(v) + i, rand() % v[i]) - begin(v) - 1;
        return {r[k][0] + rand() % (r[k][2] - r[k][0] + 1),
                r[k][1] + rand() % (r[k][3] - r[k][1] + 1)};
    }
};