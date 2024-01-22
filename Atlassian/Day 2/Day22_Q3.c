/*
**********FIND BEAUTIFUL INDICES IN THE GIVEN ARRAY I**********
You are given a 0-indexed string s, a string a, a string b, and an integer k.

An index i is beautiful if:

0 <= i <= s.length - a.length
s[i..(i + a.length - 1)] == a
There exists an index j such that:
0 <= j <= s.length - b.length
s[j..(j + b.length - 1)] == b
|j - i| <= k
Return the array that contains beautiful indices in sorted order from smallest to largest.

 

Example 1:

Input: s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
Output: [16,33]
Explanation: There are 2 beautiful indices: [16,33].
- The index 16 is beautiful as s[16..17] == "my" and there exists an index 4 with s[4..11] == "squirrel" and |16 - 4| <= 15.
- The index 33 is beautiful as s[33..34] == "my" and there exists an index 18 with s[18..25] == "squirrel" and |33 - 18| <= 15.
Thus we return [16,33] as the result.
Example 2:

Input: s = "abcd", a = "a", b = "a", k = 4
Output: [0]
Explanation: There is 1 beautiful index: [0].
- The index 0 is beautiful as s[0..0] == "a" and there exists an index 0 with s[0..0] == "a" and |0 - 0| <= 4.
Thus we return [0] as the result.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void buildNexts(
    const char *const needle,
    const int needleLen,
    int *const nexts)
{
    assert(needleLen >= 1);

    nexts[0] = 0;
    for (int i = 1; i < needleLen; i += 1)
    {
        int last = nexts[i - 1];
        while (1)
        {
            if (needle[last] == needle[i])
            {
                nexts[i] = last + 1;
                break;
            }

            if (0 == last)
            {
                nexts[i] = 0;
                break;
            }

            last = nexts[last - 1];
        }
    }
}

int *strStrAll(
    const char *const hayStack,
    const char *const needle,

    int *const pRetsLen)
{
    const int needleLen = strlen(needle);
    assert(needleLen >= 1);
    int nexts[needleLen];
    buildNexts(needle, needleLen, nexts);

    const int hayStackLen = strlen(hayStack);

    int *const rets = (int *)malloc(sizeof(int) * hayStackLen);
    *pRetsLen = 0;

    for (int i = 0, j = 0; i < hayStackLen;)
    {
        if (hayStack[i] == needle[j])
        {
            i += 1;
            j += 1;

            if (needleLen == j)
            {
                rets[*pRetsLen] = i - j;
                *pRetsLen += 1;

                j = nexts[j - 1];
            }
        }
        else
        {
            if (0 == j)
                i += 1;
            else
                j = nexts[j - 1];
        }
    }

    return rets;
}

//-------- --------

int *beautifulIndices(
    const char *const hayStack,
    const char *const needle1,
    const char *const needle2,
    const int maxDiff,

    int *const pRetsLen // out
)
{
    int needle2IdxsLen;
    int *needle2Idxs = strStrAll(hayStack, needle2, &needle2IdxsLen);

    int needle1IdxsLen;
    int *needle1Idxs = strStrAll(hayStack, needle1, &needle1IdxsLen);

    int *const rets = (int *)malloc(sizeof(int) * needle1IdxsLen);
    *pRetsLen = 0;

    int first = 0, nextOfLast = 0;
    for (int i = 0; i < needle1IdxsLen; i += 1)
    {
        const int cur = needle1Idxs[i];

        const int min = cur - maxDiff;
        while (
            first < needle2IdxsLen &&
            needle2Idxs[first] < min)
        {
            first += 1;
        }

        const int max = cur + maxDiff;
        while (
            nextOfLast < needle2IdxsLen &&
            needle2Idxs[nextOfLast] <= max)
        {
            nextOfLast += 1;
        }

        if (nextOfLast - first >= 1)
        {
            rets[*pRetsLen] = cur;
            *pRetsLen += 1;
        }
    }

    free(needle2Idxs);
    needle2Idxs = NULL;

    free(needle1Idxs);
    needle1Idxs = NULL;

    return rets;
}