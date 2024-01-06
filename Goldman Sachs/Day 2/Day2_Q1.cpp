/*
**********COMBINATION SUM III**********
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.



Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int k)
    {
        if (target == 0)
        {
            if (ds.size() == k)
                ans.push_back(ds);
            return;
        }
        if (target < 0)
            return;
        for (int i = ind; i < arr.size(); i++)
        {
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds, k);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target, int k)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds, k);
        return ans;
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans = combinationSum2(candidates, n, k);
        return ans;
    }
};