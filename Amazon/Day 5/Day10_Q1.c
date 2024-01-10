/*
**********WIGGLE SORT**********
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
*/
#include <stdio.h>
#include <stdlib.h>

void wiggleSort(int *nums, int numsSize)
{
    int arr[5001];
    for (int i = 0; i < 5001; i++)
        arr[i] = 0;

    for (int i = 0; i < numsSize; i++)
        arr[nums[i]]++;

    int end = 5000;
    int in = 1;
    while (in < numsSize && end > -1)
    {
        if (arr[end] == 0)
        {
            end--;
            continue;
        }
        else
        {
            nums[in] = end;
            in += 2;
            arr[end]--;
        }
    }
    in = 0;
    while (in < numsSize && end > -1)
    {
        if (arr[end] == 0)
        {
            end--;
            continue;
        }
        else
        {
            nums[in] = end;
            in += 2;
            arr[end]--;
        }
    }
}