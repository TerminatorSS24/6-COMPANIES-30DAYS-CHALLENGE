/*
**********lETTER COMBINATIONS OF A PHONE NUMBER**********
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

image: https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;

        vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currentCombination;
        backtrack(digits, mappings, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(const string &digits, const vector<string> &mappings, int index, string &currentCombination, vector<string> &result)
    {
        if (index == digits.length())
        {
            result.push_back(currentCombination);
            return;
        }

        int digit = digits[index] - '0';
        for (char letter : mappings[digit])
        {
            currentCombination.push_back(letter);
            backtrack(digits, mappings, index + 1, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};
