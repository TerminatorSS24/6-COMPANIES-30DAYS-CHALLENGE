/*
**********COUNT THE NUMBERS OF SQUARE FREE SUBJECTS**********
You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.
Example 2:

Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1000000007;
    long long dp[1000][1025][2];
    long long count(int j, int mask, vector<int> &res, int x)
    {

        if (j == res.size())
        {

            if (x == 0)
                return 0;
            return 1;
        }
        if (dp[j][mask][x] != -1)
            return dp[j][mask][x];

        long long ans = 0ll;

        if (res[j] == -1) 
            return dp[j][mask][x] = count(j + 1, mask, res, x);        

        ans = count(j + 1, mask, res, x);

        if ((mask & res[j]) == 0)
            ans = ((ans % mod) + count(j + 1, mask | res[j], res, 1) % mod) % mod;
        return dp[j][mask][x] = ans;
    }

    int squareFreeSubsets(vector<int> &nums)
    {
        vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> res;
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int j = 0;
            int mask = 0;
            while (x != 1)
            {
                int k = 0;
                while (x % prime[j] == 0)
                {
                    mask = (mask | (1 << j));
                    x = x / prime[j];
                    k++;
                }
                if (k > 1)
                {
                    mask = -1;
                    break;
                }
                j++;
            }
            res.push_back(mask);
        }
        return count(0, 0, res, 0);
    }
};