/*
**********MAXIMUM LENGTH OF REPEATED ARRAY**********
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MODD 49999

int *X, *Y;
int M, N;
int h[1000];
bool search(int hx, int len, int k)
{
    for (int i = 0; i < M - len + 1; i++)
        if (h[i] == hx)
        {
            for (int j = i; j < i + len; j++, k++)
                if (X[j] != Y[k])
                    return 0;
            return 1;
        }
    return 0;
}

bool subarray_present2(int len)
{
    if (len < 0)
        return 0;
    if (!len)
        return 1;

    int highest_power_x = 1;
    h[0] = X[0];
    for (int i = 1; i < len; i++)
    {
        h[0] *= 101;
        h[0] += X[i];
        highest_power_x *= 101;

        h[0] %= MODD;
        highest_power_x %= MODD;
    }
    for (int i = 1; i < M - len + 1; i++)
        h[i] = (((h[i - 1] + MODD) - (highest_power_x * X[i - 1]) % MODD) * 101 + X[i + len - 1]) % MODD;
    int h0 = Y[0];
    for (int i = 1; i < len; i++)
    {
        h0 *= 101;
        h0 += Y[i];
        h0 %= 49999;
    }
    if (search(h0, len, 0))
        return 1;
    int hx;
    for (int i = 1; i < N - len + 1; i++)
    {
        hx = ((((h0 + MODD) - (highest_power_x * Y[i - 1]) % MODD)) * 101 + Y[i + len - 1]) % MODD;
        if (search(hx, len, i))
            return 1;
        h0 = hx;
    }
    return 0;
}
int findLength(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    X = nums1;
    Y = nums2;
    M = nums1Size;
    N = nums2Size;
    int l = 0;
    int r = M < N ? (M) : (N);
    int m;
    if (subarray_present2(r))
        return r;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (subarray_present2(m))
        {
            if (!subarray_present2(m + 1))
                return m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return m;
}
