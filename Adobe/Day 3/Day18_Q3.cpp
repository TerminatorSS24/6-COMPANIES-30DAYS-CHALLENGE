/*
**********LONGEST WORD IN DICTIONARY THROUGH DELETING**********
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(string &a, string &b)
    {
        if (a.size() == b.size())
            return a < b;
        return a.size() > b.size();
    }
    bool present(string &word, unordered_map<char, vector<int>> &mp)
    {
        int x = 0;
        for (int i = 0; i < word.size(); i++)
        {
            auto it = lower_bound(mp[word[i]].begin(), mp[word[i]].end(), x);
            if (it == mp[word[i]].end())
                return false;
            else
            {
                x = *it;
                x++;
            }
        }
        return true;
    }
    string findLongestWord(string s, vector<string> &d)
    {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        sort(begin(d), end(d), comp);
        string ans = "";
        for (int i = 0; i < d.size(); i++)
        {
            if (present(d[i], mp))
            {
                ans = d[i];
                break;
            }
        }

        return ans;
    }
};