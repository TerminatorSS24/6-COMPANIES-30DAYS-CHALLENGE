/*
**********FOLLOWING A NUMBER PATTERN**********
Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
Example 2:

Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
Your Task:

You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ Length of String ≤ 8


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        // code here
        S += 'I'; /* add one I at the END. */
        int n = S.length();
        int MinDigit = 1;
        string out;
        for (int i = 0; i < n; i++)
            out += '0'; /* Initialise the output string. */
        for (int i = 0; i < n; i++)
        {
            if (S[i] == 'I')
            {
                out[i] = ('0' + MinDigit);
                MinDigit++;
                int j = i - 1;
                while (j >= 0 && S[j] == 'D')
                {
                    out[j] = ('0' + MinDigit);
                    MinDigit++;
                    j--;
                }
            }
        }

        return out;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}

// } Driver Code Ends