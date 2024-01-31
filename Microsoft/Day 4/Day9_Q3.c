/*
**********MAX PRODUCT OF LENGTH OF TWO PALINDROMIC SEQUENCES**********
Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.

 

Example 1:
image:https://assets.leetcode.com/uploads/2021/08/24/two-palindromic-subsequences.png
example-1
Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.
Example 2:

Input: s = "bb"
Output: 1
Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
The product of their lengths is: 1 * 1 = 1.
Example 3:

Input: s = "accbcaxxcxx"
Output: 25
Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
The product of their lengths is: 5 * 5 = 25. 
*/
#include <stdio.h>
#include <stdlib.h>

int maxPalindromic(char *str)
{
    if (strlen(str) == 1)
        return 1;
    int len = strlen(str);
    int dp[len][len];

    dp[0][0] = 1;
    for (int i = 1; i < len; ++i)
    {
        dp[i][i] = 1;
        dp[i - 1][i] = str[i] == str[i - 1] ? 2 : 1;
    }

    for (int i = 2; i < len; ++i)
    {
        for (int j = 0; i + j < len; ++j)
        {
            int head = j, tail = i + j;
            dp[head][tail] = str[head] == str[tail] ? dp[head + 1][tail - 1] + 2 : fmax(dp[head + 1][tail], dp[head][tail - 1]);
        }
    }

    return dp[0][len - 1];
}

int maxProduct(char *s)
{
    int res = 0, mask = (1 << strlen(s)) - 1;

    for (int i = 1; i < mask; ++i)
    {
        int cnt1 = 0, cnt2 = 0;
        char tmp1[strlen(s)], tmp2[strlen(s)];
        for (int j = strlen(s) - 1; j >= 0; --j)
        {
            if (1 << j & i)
                tmp1[cnt1++] = s[j];
            else
                tmp2[cnt2++] = s[j];
        }

        tmp1[cnt1] = '\0';
        tmp2[cnt2] = '\0';
        int len1 = maxPalindromic(tmp1), len2 = maxPalindromic(tmp2);
        res = fmax(res, len1 * len2);
    }

    return res;
}