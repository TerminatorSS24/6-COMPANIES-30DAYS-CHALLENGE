/*
**********RUSSIAN DOLL ENVELOPES**********
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int *envelope1 = *(int **)a;
    int *envelope2 = *(int **)b;

    if (envelope1[0] == envelope2[0])
        return envelope2[1] - envelope1[1];

    return envelope1[0] - envelope2[0];
}

int maxEnvelopes(int **envelopes, int envelopesSize, int *envelopesColSize)
{
    if (envelopesSize <= 1)
        return envelopesSize;

    qsort(envelopes, envelopesSize, sizeof(int *), cmp);

    int dp[envelopesSize];
    int maxCount = 1;

    for (int i = 0; i < envelopesSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (envelopes[i][1] > envelopes[j][1])
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
        maxCount = maxCount > dp[i] ? maxCount : dp[i];
    }

    return maxCount;
}
