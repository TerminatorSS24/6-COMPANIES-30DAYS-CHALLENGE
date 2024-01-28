/*
**********REPEATED DNA SEQUENCE**********
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/
#include <stdio.h>
#include <stdlib.h>
struct HashTable
{
    char key[11];
    int val;
    UT_hash_handle hh;
};

struct HashTable *freq;

struct HashTable *find(char *key)
{
    struct HashTable *temp;
    HASH_FIND_STR(freq, key, temp);
    return temp;
}
int insert(char *key)
{
    struct HashTable *it = find(key);
    if (it == NULL)
    {
        struct HashTable *temp =
            (struct HashTable *)malloc(sizeof(struct HashTable));
        strcpy(temp->key, key);
        temp->val = 1;

        HASH_ADD_STR(freq, key, temp);

        return temp->val;
    }
    else
    {
        (it->val)++;
        return it->val;
    }
    return -1;
}
void delete_all()
{
    struct HashTable *curr, *temp;
    HASH_ITER(hh, freq, curr, temp)
    {
        HASH_DEL(freq, curr);
        free(curr);
    }
}

void substr(char *dst, const char *src, unsigned int start,
            unsigned int count)
{
    strncpy(dst, src + start, count);
    dst[count] = '\0';
}
char **findRepeatedDnaSequences(char *s, int *returnSize)
{
    const int n = strlen(s);
    if (n < 10)
    {
        *returnSize = 0;
        return NULL;
    }
    char **temp = (char **)calloc(n - 10 + 1, sizeof(char *));
    for (int i = 0; i + 10 < n + 1; ++i)
        temp[i] = (char *)calloc(11, sizeof(char));
    int size = 0;

    struct HashTable *freq = NULL;

    char *sub = (char *)calloc(11, sizeof(char));
    for (int i = 0; i + 10 < n + 1; ++i)
    {
        substr(sub, s, i, 10);
        if (insert(sub) == 2)
            strcpy(temp[size++], sub);
    }

    char **result = (char **)calloc(size, sizeof(char *));
    *returnSize = size;
    for (int i = 0; i < size; ++i)
    {
        result[i] = (char *)calloc(11, sizeof(char));
        strcpy(result[i], temp[i]);
    }

    for (int i = 0; i + 10 < n + 1; ++i)
        free(temp[i]);
    free(temp);
    free(sub);
    delete_all();
    return result;
}