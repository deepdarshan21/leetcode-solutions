#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 49.35%
   Memory Usage: 13.9 MB less than: 30.86%
   Remarks:
*/

class Solution {
   public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(help(n - 1, dp, cost), help(n - 2, dp, cost));
    }
    int help(int curr, vector<int> &dp, vector<int> &cost) {
        if (curr <= 1) return dp[curr] = cost[curr];
        if (dp[curr] != -1) return dp[curr];
        dp[curr] = cost[curr] + min(help(curr - 1, dp, cost), help(curr - 2, dp, cost));
        return dp[curr];
    }
};