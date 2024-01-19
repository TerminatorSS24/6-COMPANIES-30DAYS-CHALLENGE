/*
**********MINIMUM COST OF A PATH WITH SPECIAL ROADS**********
You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

 

Example 1:

Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
Output: 5
Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.
Example 2:

Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
Output: 7
Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ipii = pair<int, pair<int, int>>;
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        map<pair<int, int>, int> spr; 
        spr[{start[0], start[1]}] = 0;
        vector<vector<int>> roads;
        for(auto i : specialRoads) {
            int a = i[0], b = i[1], c = i[2], d = i[3], cost = i[4];

            if(cost < abs(a - c) + abs(b - d)) { 
                roads.push_back({a, b, c, d, cost});
                spr[{c, d}] = abs(c - start[0]) + abs(d - start[1]);
            }
        }
        priority_queue<ipii, vector<ipii>, greater<ipii>> pq; 

        pq.push({0, {start[0], start[1]}}); 
        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int dist = curr.first, x = curr.second.first, y = curr.second.second;

            for(auto &i : roads) {
                int a = i[0], b = i[1], c = i[2], d = i[3], cost = i[4];
                if(spr[{c, d}] > dist + abs(a - x) + abs(b - y) + cost) {
                    spr[{c, d}] = dist + abs(a - x) + abs(b - y) + cost;
                    pq.push({spr[{c, d}], {c, d}});
                }
            }
        }

        int tx = target[0], ty = target[1];
        int ans = abs(tx - start[0]) + abs(ty - start[1]);

        for(auto &i : roads) {
            int c1 = abs(tx - i[2]), d1 = abs(ty - i[3]);
            ans = min(ans, c1 + d1 + spr[{i[2], i[3]}]);
        }

        return ans;
    }
};