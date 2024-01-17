/*
**********SPECIAL PERMUTATIONS**********
You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [2,3,6]
Output: 2
Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
Example 2:

Input: nums = [1,4,3]
Output: 2
Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int specialPerm(vector<int> &a)
    {
        int n = a.size();
        int mod = 1e9 + 7;
        int dp[(1 << n) + 5][n + 5];
        memset(dp, -1, sizeof dp);

        function<int(int, int)> dfs = [&](int mask, int prev_idx) -> int
        {
            if (mask == (1 << n) - 1)
                return 1;
            int &ans = dp[mask][prev_idx];
            if (ans != -1)
                return ans;
            ans = 0;
            for (int i = 0; i < n; i++)
                if (!(mask & (1 << i)))
                    if (a[i] % a[prev_idx] == 0 or a[prev_idx] % a[i] == 0)
                    {
                        ans += dfs(mask | (1 << i), i);
                        ans %= mod;
                    }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dfs(1 << i, i);
            ans %= mod;
        }
        return ans;
    }
};