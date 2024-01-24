/*
**********THE NUMBER OF GOOD SUBSETS**********
You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.

For example, if nums = [1, 2, 3, 4]:
[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
Return the number of different good subsets in nums modulo 109 + 7.

A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.



Example 1:

Input: nums = [1,2,3,4]
Output: 6
Explanation: The good subsets are:
- [1,2]: product is 2, which is the product of distinct prime 2.
- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [1,3]: product is 3, which is the product of distinct prime 3.
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [3]: product is 3, which is the product of distinct prime 3.
Example 2:

Input: nums = [4,2,3,15]
Output: 5
Explanation: The good subsets are:
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [2,15]: product is 30, which is the product of distinct primes 2, 3, and 5.
- [3]: product is 3, which is the product of distinct prime 3.
- [15]: product is 15, which is the product of distinct primes 3 and 5
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int spf[31];
    int n = 30;
    int mod = 1e9 + 7;
    int mp[30];

public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        run();
        bool st[31] = {0};
        for (int i = 1; i <= 30; ++i)
        {
            if (!is_valid(i))
                st[i] = true;
        }

        int arr[31] = {0};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (st[nums[i]])
                continue;
            ++arr[nums[i]];
        }
        nums = vector<int>();
        for (int i = 2; i <= 30; ++i)
        {
            if (arr[i])
                nums.push_back(i);
        }
        long long ones = 1;
        int cnt1 = arr[1];
        while (cnt1--)
        {
            ones *= 2;
            ones %= mod;
        }
        int n = nums.size();
        long long ans = 0;
        for (int i = 1; i < (1 << n); ++i)
        {
            int ok = 1;
            int cur = 0;
            long long cnt = 1;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    int tmp = get_bits(nums[j]);
                    if (tmp & cur)
                    {
                        ok = 0;
                        break;
                    }
                    cur |= tmp;
                    cnt *= arr[nums[j]];
                    cnt %= mod;
                }
            }
            if (ok)
            {
                ans += (cnt * ones);
                ans %= mod;
            }
        }
        return ans;
    }

    void run()
    {
        for (int i = 2; i <= n; i++)
            spf[i] = i;

        for (int i = 2; i <= n; i++)
            if (spf[i] == i)
                for (int j = i + i; j <= n; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
        int idx = 0;
        for (int i = 2; i <= n; i++)
            if (!mp[spf[i]])
                mp[spf[i]] = ++idx;
    }

    int is_valid(int n)
    {
        int prv = -1;
        bool ok = 1;
        while (n != 1)
        {
            if (prv == spf[n])
                ok = 0;
            prv = spf[n];
            n /= spf[n];
        }
        return ok;
    }
    int get_bits(int n)
    {
        int ret = 0;
        while (n != 1)
        {
            ret |= 1 << mp[spf[n]];
            n /= spf[n];
        }
        return ret;
    }
};