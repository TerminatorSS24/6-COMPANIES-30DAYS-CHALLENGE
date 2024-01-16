/*
**********TRIM A BINARY SEARCH TREE**********
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

 

Example 1:

image:https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:

image: https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
*/
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    typedef struct TreeNode Tree;

    struct TreeNode
    {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
    };
    static void Tree_destroy(Tree *const pTree)
    {
        if (NULL == pTree)
        {
            return;
        }

        Tree_destroy(pTree->left);
        Tree_destroy(pTree->right);

        free(pTree);
    }

    static int g_low;
    static int g_high;

    static Tree *trimBST_recurse(Tree *const pRoot)
    {
        if (NULL == pRoot)
        {
            return NULL;
        }

        Tree
            *const pLeft = pRoot->left,
                *const pRight = pRoot->right;

        if (pRoot->val < g_low)
        {
            pRoot->right = NULL;
            Tree_destroy(pRoot);
            return trimBST_recurse(pRight);
        }
        else if (pRoot->val > g_high)
        {
            pRoot->left = NULL;
            Tree_destroy(pRoot);
            return trimBST_recurse(pLeft);
        }
        else
        {
            pRoot->left = trimBST_recurse(pRoot->left);
            pRoot->right = trimBST_recurse(pRoot->right);
            return pRoot;
        }
    }

    Tree *trimBST(Tree *const pRoot, const int low, const int high)
    {
        g_low = low;
        g_high = high;

        return trimBST_recurse(pRoot);
    }