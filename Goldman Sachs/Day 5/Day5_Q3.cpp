/*
**********NUMBER OF WAYS TO REACH A POSITION AFTER EXACTLY K STEPS**********
You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.

 

Example 1:

Input: startPos = 1, endPos = 2, k = 3
Output: 3
Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.
Example 2:

Input: startPos = 2, endPos = 5, k = 10
Output: 0
Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long modularExponentiation(long long base, long long exponent, long long modulus)
    {

        long long result = 1;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
                result = (result * base) % modulus;
            
            base = (base * base) % modulus;
            exponent = exponent / 2;
        }
        return result;
    }

    long long modularMultiplicativeInverse(long long number, long long modulus)
    {

        return modularExponentiation(number, modulus - 2, modulus);
    }

    long long combination(int n, int r, int modulus)
    {

        if (n < r)
            return 0;
        if (r == 0)
            return 1;

        long long factorial[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++)
            factorial[i] = (factorial[i - 1] * i) % modulus;
        
        long long numerator = factorial[n];
        long long denominator = (factorial[r] * factorial[n - r]) % modulus;
        long long moduloInverse = modularMultiplicativeInverse(denominator, modulus);
        return (numerator * moduloInverse) % modulus;
    }

    int numberOfWays(int startPos, int endPos, int k)
    {

        int distance = abs(endPos - startPos);

        if (k < distance)
            return 0;
        else if (distance == k)
            return 1;
        else if ((k - distance) % 2 != 0)
            return 0;
        long long forwardSteps = distance + (k - distance) / 2;
        long long backwardSteps = (k - distance) / 2;
        long long modulus = 1000000007;

        return combination(forwardSteps + backwardSteps, forwardSteps, modulus);
    }
};