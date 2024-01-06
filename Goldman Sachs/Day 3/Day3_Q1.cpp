/*
**********FIND MISSING AND REPEATING**********
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
*/
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
         int xor_all = 0;
        for(int i = 0; i < n; i++)
        {
            xor_all = (xor_all^(i+1));
            xor_all = (xor_all^arr[i]);
        }
        
        int first_one_position=0;
        while((xor_all&1) == 0){
            xor_all = (xor_all>>1);
            first_one_position++;
        }
        
        int one_grp=0,zero_grp=0;
        for(int i = 0; i < n; i++)
        {
            if(((i+1)>>first_one_position)&1 == 1) one_grp = (one_grp^(i+1));
            else zero_grp = (zero_grp^(i+1));
            
            if((arr[i]>>first_one_position)&1 == 1) one_grp = (one_grp^arr[i]);
            else zero_grp = (zero_grp^arr[i]);
        }
        
        for(int i = 0; i < n; i++)
            if(arr[i] == one_grp) return {one_grp, zero_grp};
        return {zero_grp, one_grp};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends