/*
**********NUMBER OF GOOD LEAF NODES PAIR**********
You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.



Example 1:

image: https://assets.leetcode.com/uploads/2020/07/09/e1.jpg

Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
Example 2:

image: https://assets.leetcode.com/uploads/2020/07/09/e2.jpg

Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int *DFS(struct TreeNode *root, int distance, int *ansCnt, int *idx)
{
    if (!root->left && !root->right)
    {
        int *ret = (int *)calloc(1, sizeof(int));
        ret[0] = 1;
        (*idx) = 1;
        return ret;
    }
    int lidx = 0, ridx = 0;
    int *lbuf;
    int *rbuf;
    if (root->left)
        lbuf = DFS(root->left, distance, ansCnt, &lidx);
    if (root->right)
        rbuf = DFS(root->right, distance, ansCnt, &ridx);

    int *ret = (int *)calloc(lidx + ridx, sizeof(int));
    if (lidx && ridx)
    {
        int cnt = 0;
        for (int i = 0; i < lidx; i++)
        {
            for (int j = 0; j < ridx; j++)
            {
                int dis = lbuf[i] + rbuf[j];
                (*ansCnt) += (dis <= distance) ? 1 : 0;
            }
        }
    }
    if (lidx)
        for (int i = 0; i < lidx; i++)
            if (lbuf[i] + 1 < distance)
                ret[(*idx)++] = lbuf[i] + 1;
    if (ridx)
        for (int i = 0; i < ridx; i++)
            if (rbuf[i] + 1 < distance)
                ret[(*idx)++] = rbuf[i] + 1;

    return ret;
}

int countPairs(struct TreeNode *root, int distance)
{
    if (!root)
        return 0;
    int ansCnt = 0, idx = 0;
    DFS(root, distance, &ansCnt, &idx);
    return ansCnt;
}