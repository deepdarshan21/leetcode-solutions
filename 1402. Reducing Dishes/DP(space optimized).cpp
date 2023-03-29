#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(space optimized)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 44 ms faster than: 41.78%
   Memory Usage: 8.5 MB less than: 62.10%
   Remarks:
*/

class Solution {
   public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> dp(n + 2, 0);
        vector<int> help(n + 2, 0);
        sort(satisfaction.begin(), satisfaction.end());

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = n; time > 0; time--) {
                if (satisfaction[idx] >= 0)
                    help[time] = satisfaction[idx] * time + dp[time + 1];
                else {
                    int take, notTake;
                    take = satisfaction[idx] * time + dp[time + 1];
                    notTake = dp[time];
                    help[time] = max(take, notTake);
                }
            }
            swap(help, dp);
        }

        return dp[1];
    }
};