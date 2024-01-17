/*
**********MATRIX CELLS IN DISTANCE ORDER**********
You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.

 

Example 1:

Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (0, 0) to other cells are: [0,1]
Example 2:

Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
Example 3:

Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int *returnSize, int **returnColumnSizes)
{
    const int cellCnt = rows * cols;
    *returnColumnSizes = (int *)malloc(sizeof(int) * cellCnt);
    int **rets = (int **)malloc(sizeof(int *) * cellCnt);
    *returnSize = 0;
    (*returnColumnSizes)[*returnSize] = 2;
    rets[*returnSize] = (int *)malloc(sizeof(int) * 2);
    rets[*returnSize][0] = rCenter;
    rets[*returnSize][1] = cCenter;
    *returnSize += 1;
    const int maxDistance = (rows - 1) + (cols - 1);
    for (int curDistance = 1; curDistance <= maxDistance; curDistance += 1)
    {
        for (int diff1 = curDistance, diff2 = 0; diff1 > 0; diff1 -= 1, diff2 += 1)
        {
            const int cells[4][2] = {
                {rCenter - diff1, cCenter + diff2},
                {rCenter + diff2, cCenter + diff1},
                {rCenter + diff1, cCenter - diff2},
                {rCenter - diff2, cCenter - diff1}};
            for (int i = 0; i < 4; i += 1)
            {
                if (
                    (cells[i][0] >= 0 && cells[i][0] < rows) &&
                    (cells[i][1] >= 0 && cells[i][1] < cols))
                {
                    (*returnColumnSizes)[*returnSize] = 2;
                    rets[*returnSize] = (int *)malloc(sizeof(int) * 2);
                    rets[*returnSize][0] = cells[i][0];
                    rets[*returnSize][1] = cells[i][1];
                    *returnSize += 1;
                }
            }
        }
    }

    return rets;
}