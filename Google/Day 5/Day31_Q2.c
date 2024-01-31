/*
**********DESIGN ADD AND SEARCH WORDS DATA STRUCTURE**********
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *next[26];
    bool is_end;
} node_t;

typedef struct
{
    node_t trie;
} WordDictionary;

bool trieSearch(node_t *head, char *word)
{
    char c;
    bool ans = false;

    while (*word)
    {

        if (*word == '.')
        {
            for (int i = 0; i < 26 && ans == false; i++)
                if (head->next[i] != NULL) 
                    ans = trieSearch(head->next[i], word + 1);
            return ans;
        }
        else
        {
            c = *word - 'a';

            if (head->next[c] == NULL)
                return false;
        }

        head = head->next[c];
        word++;
    }

    return head->is_end;
}

void trieRelease(node_t *head)
{
    if (head)
    {
        for (int i = 0; i < 26; i++)
            trieRelease(head->next[i]);
        free(head);
    }
}

WordDictionary *wordDictionaryCreate()
{
    return (WordDictionary *)calloc(1, sizeof(node_t));
}

void wordDictionaryAddWord(WordDictionary *obj, char *word)
{

    char c;
    node_t *head = &obj->trie;

    while (*word)
    {

        c = *word - 'a';

        if (head->next[c] == NULL)
            head->next[c] = (node_t *)calloc(1, sizeof(node_t));

        head = head->next[c];
        word++;
    }

    head->is_end = true;
}

bool wordDictionarySearch(WordDictionary *obj, char *word)
{
    return trieSearch(&obj->trie, word);
}

void wordDictionaryFree(WordDictionary *obj)
{

    for (int i = 0; i < 26; i++)
        trieRelease(obj->trie.next[i]);

    free(obj);
}