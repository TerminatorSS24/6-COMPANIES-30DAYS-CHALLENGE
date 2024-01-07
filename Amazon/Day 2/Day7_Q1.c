/*
**********IMAGE SMOOTHER**********
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

image: https://assets.leetcode.com/uploads/2021/05/03/smoother-grid.jpg

Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/05/03/smooth-grid.jpg

Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:

image: https://assets.leetcode.com/uploads/2021/05/03/smooth2-grid.jpg

Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
const int dir[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int **imageSmoother(int **img, int imgSize, int *imgColSize, int *returnSize, int **returnColumnSizes)
{
    int **ret = malloc(sizeof(int *) * imgSize);
    *returnSize = imgSize;
    *returnColumnSizes = calloc(imgSize, sizeof(int));

    for (register int r = 0; r < imgSize; r++)
    {
        ret[r] = calloc(imgColSize[0], sizeof(int));
        for (register int c = 0; c < imgColSize[0]; c++)
        {
            int count = 0, sum = 0;
            for (register int idx = 0; idx < 9; idx++)
            {
                int rr = r + dir[idx][0], cc = c + dir[idx][1];
                if (rr >= 0 && rr < imgSize && cc >= 0 && cc < imgColSize[0])
                {
                    count++;
                    sum += img[rr][cc];
                }
            }
            ret[r][c] = sum / count;
        }
        (*returnColumnSizes)[r] = imgColSize[0];
    }

    return ret;
}