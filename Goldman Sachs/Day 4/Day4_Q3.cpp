/*
**********MAXCIMUM SUM BST IN BINARY TREE**********
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

image: https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png

Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:

image: https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png

Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Nodevalue
{
public:
    int maxNode, minNode;
    long Sum;
    Nodevalue(int maxNode, int minNode, long Sum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->Sum = Sum;
    }
};
class Solution
{
public:
    long ans = 0;
    Nodevalue solve(TreeNode *root)
    {
        if (root == NULL)
            return Nodevalue(INT_MIN, INT_MAX, 0);
        Nodevalue left = solve(root->left);
        Nodevalue right = solve(root->right);
        if (root->val > left.maxNode && root->val < right.minNode)
        {
            ans = max(ans, root->val + left.Sum + right.Sum);
            return Nodevalue(max(root->val, right.maxNode), min(root->val, left.minNode), root->val + left.Sum + right.Sum);
        }
        return Nodevalue(INT_MAX, INT_MIN, root->val + left.Sum + right.Sum);
    }
    int maxSumBST(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        solve(root);
        return ans;
    }
};