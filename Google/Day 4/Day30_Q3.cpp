/*
**********SUM OF SCORES OF BUILT STRING**********
You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.

For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
The score of si is the length of the longest common prefix between si and sn (Note that s == sn).

Given the final string s, return the sum of the score of every si.



Example 1:

Input: s = "babab"
Output: 9
Explanation:
For s1 == "b", the longest common prefix is "b" which has a score of 1.
For s2 == "ab", there is no common prefix so the score is 0.
For s3 == "bab", the longest common prefix is "bab" which has a score of 3.
For s4 == "abab", there is no common prefix so the score is 0.
For s5 == "babab", the longest common prefix is "babab" which has a score of 5.
The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.
Example 2:

Input: s = "azbazbzaz"
Output: 14
Explanation:
For s2 == "az", the longest common prefix is "az" which has a score of 2.
For s6 == "azbzaz", the longest common prefix is "azb" which has a score of 3.
For s9 == "azbazbzaz", the longest common prefix is "azbazbzaz" which has a score of 9.
For all other si, the score is 0.
The sum of the scores is 2 + 3 + 9 = 14, so we return 14.
*/
#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define vec vector

using ll = long long;
using pll = pair<ll, ll>;

constexpr int P = 31;
constexpr int P2 = 33;
constexpr int M = (int)1e9 + 7;
constexpr int M2 = (int)1e9 + 9;

class Solution
{
public:
    long long sumScores(string s)
    {
        int n = s.size();
        vec<pll> hashes(n + 1), powers(n + 1);
        for (ll h1 = 0, h2 = 0, p1 = 1, p2 = 1, i = 0; i < n;
             i++, p1 = (p1 * P) % M, p2 = (p2 * P2) % M2)
        {
            h1 += ((s[i] - 'a' + 1) * p1) % M;
            h1 %= M;
            h2 += ((s[i] - 'a' + 1) * p2) % M2;
            h2 %= M2;
            powers[i + 1] = {p1, p2};
            hashes[i + 1] = {h1, h2};
        }

        vec<ll> scores(n + 1);
        for (int i = n; i > 0; i--)
        {
            int l = 0, r = n - i, score = 0;
            while (l <= r)
            {
                int len = (l + r) / 2;
                ll h1 = (hashes[i + len].first - hashes[i - 1].first + M) % M;
                ll h2 = (hashes[i + len].second - hashes[i - 1].second + M2) % M2;
                ll h1_begin = (hashes[len + 1].first * powers[i].first) % M;
                ll h2_begin = (hashes[len + 1].second * powers[i].second) % M2;
                if (h1 == h1_begin && h2 == h2_begin)
                {
                    score = len + 1;
                    l = len + 1;
                }
                else
                {
                    r = len - 1;
                }
            }
            scores[i] = score;
        }
        return accumulate(all(scores), 0LL);
    }
};