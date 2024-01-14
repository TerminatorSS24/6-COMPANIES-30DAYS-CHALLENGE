/*
**********TOP K FREQUENT WORDS**********
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m1;
        map<int, set<string>> m2;
        int c = 0;
        for (auto &i : words)
            ++m1[i];
        for (auto &itr : m1)
            m2[itr.second].insert(itr.first);
        vector<string> v;
        for (auto itr = m2.rbegin(); itr != m2.rend(); ++itr)
        {
            for (auto &i : itr->second)
            {
                v.push_back(i);
                if (v.size() >= k)
                    return v;
            }
        }
        return v;
    }
};