/*
**********BULLS AND COWS**********
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
*/
#include <stdio.h>
#include <stdlib.h>

char *getHint(char *secret, char *guess)
{
    int cows = 0, bulls = 0;
    int n = strlen(secret);
    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            secret[i] = guess[i] = 'X';
            bulls++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (secret[i] == guess[j] && secret[i] != 'X')
            {
                cows++;
                guess[j] = 'Y';
                break;
            }
        }
    }
    char *ans;
    ans = (char *)calloc(10, sizeof(char));
    sprintf(ans, "%dA%dB", bulls, cows);
    return ans;
}