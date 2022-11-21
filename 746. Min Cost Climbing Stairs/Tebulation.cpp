#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status:Accepted
   Runtime: 13 ms faster than: 52%
   Memory Usage: 13.9 MB less than: 30%
   Remarks:
*/

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i++) dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        return min(dp[0], dp[1]);
    }
};