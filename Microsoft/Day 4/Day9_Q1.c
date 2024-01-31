/*
**********CITY WITH SMALLEST NUMBER OF THRESHOLD DISTANCE**********
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:
image: https://assets.leetcode.com/uploads/2020/01/16/find_the_city_01.png

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:

image: https://assets.leetcode.com/uploads/2020/01/16/find_the_city_02.png

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long int min(long long int a, long long int b) { return a < b ? a : b; }
int findTheCity(int n, int **edges, int edgesSize, int *edgesColSize,
                int distanceThreshold)
{
    int mp[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0], v = edges[i][1], d = edges[i][2];
        mp[u][v] = d;
        mp[v][u] = d;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (k == i)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (k == j)
                    continue;
                mp[i][j] =
                    min((long long int)mp[i][j],
                        (long long int)mp[i][k] + (long long int)mp[k][j]);
            }
        }
    }

    int res = 0;
    int small = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int reach = 0;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (mp[i][j] <= distanceThreshold)
            {
                reach++;
            }
        }
        if (reach <= small)
        {
            res = i;
            small = reach;
        }
    }
    return res;
}