/*
**********COUNTING NICE SUBARRAYS**********
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/
#include <stdio.h>
#include <stdlib.h>

int numberOfSubarrays(int *nums, int numsSize, int k)
{
    int Hash2[100001] = {0};
    int sum = 0;
    int count = 0;
    Hash2[0] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i] % 2;
        Hash2[sum]++;
        int diff = sum - k;
        if (diff < 0)
            continue;
        count += Hash2[diff];
    }
    return count;
}