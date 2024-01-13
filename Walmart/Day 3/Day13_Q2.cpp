/*
**********FRIENDS OF APPROPRIATE AGES**********
There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

 

Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch1(vector<int> &arr, int start, int end, double tgt)
    {
        int potCand = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (1.0 * arr[mid] <= tgt)
                end = mid - 1;
            else if (1.0 * arr[mid] > tgt)
            {
                potCand = mid;
                start = mid + 1;
            }
        }

        return potCand;
    }

    int binarySearch3(vector<int> &arr, int start, int end, int tgt)
    {
        int potCand = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] <= tgt)
            {
                potCand = mid;
                end = mid - 1;
            }
            else if (arr[mid] > tgt)
                start = mid + 1;  
        }
        return potCand;
    }

    int numFriendRequests(vector<int> &ages)
    {
        sort(ages.begin(), ages.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < ages.size(); i++)
        {
            double tgt = 1.0 * ages[i];

            int idx1 = binarySearch1(ages, i, ages.size() - 1, 0.5 * tgt + 7);
            if (idx1 == -1)
                continue;

            int idx2 = ages.size() - 1;

            int idx3;
            if (ages[i] >= 100) 
                idx3 = i;
            else
            {
                idx3 = binarySearch3(ages, i, ages.size() - 1, 100);
                if (idx3 == -1)
                    continue;
            }

            int finalIdxHigh = min(idx1, idx2);
            int finalIdxLow = max(i, idx3);

            ans += (finalIdxHigh - finalIdxLow);
            if (finalIdxLow > i)
                ans++;
        }

        unordered_map<int, int> m;
        for (auto it : ages)
            m[it]++;
        for (auto it : m)
        {
            int num = it.first;
            int n = it.second;
            bool flag = 1.0 * num > 0.5 * num + 7;
            if (n > 1 && flag == true)
                ans += ((n - 1) * n) / 2;
        }

        return ans;
    }
};