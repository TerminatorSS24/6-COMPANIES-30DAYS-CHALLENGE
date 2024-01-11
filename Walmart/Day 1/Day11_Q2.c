/*
**********FIND SUBSEQUENCE OF LENGTH K WITH THE LARGEST SUM**********
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
*/
#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int idx;
    int val;
};

int cmp_pair_val(const void *a, const void *b)
{
    struct pair pa = *(const struct pair *)a;
    struct pair pb = *(const struct pair *)b;
    return pb.val - pa.val;
}

int cmp_pair_idx(const void *a, const void *b)
{
    struct pair pa = *(const struct pair *)a;
    struct pair pb = *(const struct pair *)b;
    return pa.idx - pb.idx;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxSubsequence(int *nums, int numsSize, int k, int *returnSize)
{
    struct pair *pairs = malloc(sizeof(struct pair) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        pairs[i].idx = i;
        pairs[i].val = nums[i];
    }

    qsort(pairs, numsSize, sizeof(struct pair), cmp_pair_val);
    qsort(pairs, k, sizeof(struct pair), cmp_pair_idx);
    int *sol = (int *)malloc(sizeof(int) * k);
    (*returnSize) = k;
    for (int i = 0; i < k; i++)
    {
        sol[i] = nums[pairs[i].idx];
    }

    free(pairs);
    return sol;
}