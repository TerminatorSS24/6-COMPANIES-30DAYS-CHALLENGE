/*
**********WORD BREAK**********
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find(int *uf, int i)
{
    while (uf[i] != i)
        i = uf[i];
    return i;
}

void merge(int *uf, int i, int j) { uf[find(uf, j)] = find(uf, i); }

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    int n = strlen(s);
    int *uf = calloc(n + 1, sizeof(int));
    for (int i = 0; i < n + 1; i++)
        uf[i] = i;
    for (int i = 0; i < wordDictSize; i++)
    {
        int m = strlen(wordDict[i]);
        for (int j = 0; j <= n - m; j++)
            if (!strncmp(wordDict[i], s + j, m))
                merge(uf, j, j + m);
    }
    bool ret = find(uf, n) == find(uf, 0);
    free(uf);
    return ret;
}
