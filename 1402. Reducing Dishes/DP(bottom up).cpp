#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 98 ms faster than: 5.26%
   Memory Usage: 21 MB less than: 28.33%
   Remarks:
*/

class Solution {
   public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        sort(satisfaction.begin(), satisfaction.end());

        for (int i = 0; i < n + 2; i++) dp[n][i] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = 0; time < n + 1; time++) {
                if (satisfaction[idx] >= 0) dp[idx][time] = satisfaction[idx] * time + dp[idx + 1][time + 1];
                int take, notTake;
                take = satisfaction[idx] * time + dp[idx + 1][time + 1];
                notTake = dp[idx + 1][time];
                dp[idx][time] = max(take, notTake);
            }
        }

        return dp[0][1];
    }
};