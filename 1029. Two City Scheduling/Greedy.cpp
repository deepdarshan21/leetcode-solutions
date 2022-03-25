#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        First add cost of travel to city A
        then remove the cost travel to city A and add the city B who's difference is high

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 42.77%
   Memory Usage: 7.9 MB less than: 78.03%
   Remarks:
*/

class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int minCost = 0;
        for (int i = 0; i < costs.size(); i++) {
            minCost += costs[i][0];
            costs[i][0] = costs[i][1] - costs[i][0];
        }
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size() / 2; i++) {
            minCost += costs[i][0];
        }
        return minCost;
    }
};