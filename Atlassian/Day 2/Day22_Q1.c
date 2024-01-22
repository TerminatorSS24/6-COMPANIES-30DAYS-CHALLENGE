/*
**********MAXIMIZE AREA OF SQUARE HOLD IN GRID**********
There is a grid with n + 2 horizontal bars and m + 2 vertical bars, and initially containing 1 x 1 unit cells.

The bars are 1-indexed.

You are given the two integers, n and m.

You are also given two integer arrays: hBars and vBars.

hBars contains distinct horizontal bars in the range [2, n + 1].
vBars contains distinct vertical bars in the range [2, m + 1].
You are allowed to remove bars that satisfy any of the following conditions:

If it is a horizontal bar, it must correspond to a value in hBars.
If it is a vertical bar, it must correspond to a value in vBars.
Return an integer denoting the maximum area of a square-shaped hole in the grid after removing some bars (possibly none).



Example 1:

image: https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-40-25.png

Input: n = 2, m = 1, hBars = [2,3], vBars = [2]
Output: 4
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,4], and the vertical bars are in the range [1,3].
It is allowed to remove horizontal bars [2,3] and the vertical bar [2].
One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.
The resulting grid is shown on the right.
The hole has an area of 4.
It can be shown that it is not possible to get a square hole with an area more than 4.
Hence, the answer is 4.
Example 2:

image: https://assets.leetcode.com/uploads/2023/11/04/screenshot-from-2023-11-04-17-01-02.png

Input: n = 1, m = 1, hBars = [2], vBars = [2]
Output: 4
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,3], and the vertical bars are in the range [1,3].
It is allowed to remove the horizontal bar [2] and the vertical bar [2].
To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.
The resulting grid is shown on the right.
The hole has an area of 4.
Hence, the answer is 4, and it is the maximum possible.
Example 3:

image: https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-33-35.png

Input: n = 2, m = 3, hBars = [2,3], vBars = [2,3,4]
Output: 9
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,4], and the vertical bars are in the range [1,5].
It is allowed to remove horizontal bars [2,3] and vertical bars [2,3,4].
One way to get the maximum square-shaped hole is by removing horizontal bars 2 and 3, and vertical bars 3 and 4.
The resulting grid is shown on the right.
The hole has an area of 9.
It can be shown that it is not possible to get a square hole with an area more than 9.
Hence, the answer is 9.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static int cmp_int_asc(const int *const pCur, const int *const pBase)
{
    return *pCur - *pBase;
}

static int maxConsecutive(const int *const numArr, const int numArrLen)
{
    int maxLen = 0;
    for (int i = 0; i < numArrLen;)
    {
        int curLen = 1;
        while (
            i + curLen < numArrLen &&
            numArr[i + curLen] == numArr[i] + curLen)
        {
            curLen += 1;
        }

        if (curLen > maxLen)
            maxLen = curLen;
        i += curLen;
    }
    return maxLen;
}

static int min_int_2(const int a, const int b)
{
    return (a <= b) ? a : b;
}

int maximizeSquareHoleArea(
    const int n,
    const int m,

    int *const hBarArr,
    const int hBarArrLen,

    int *const vBarArr,
    const int vBarArrLen)
{
    (void)n;
    (void)m;

    qsort(hBarArr, hBarArrLen, sizeof(int), &cmp_int_asc);
    qsort(vBarArr, vBarArrLen, sizeof(int), &cmp_int_asc);

    const int border = min_int_2(maxConsecutive(hBarArr, hBarArrLen), maxConsecutive(vBarArr, vBarArrLen)) + 1;
    return border * border;
}