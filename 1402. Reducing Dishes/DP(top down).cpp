#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 68 ms faster than: 5.72%
   Memory Usage: 21.1 MB less than: 6.44%
   Remarks:
*/

class Solution {
   public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());

        function<int(int, int)> rec = [&](int idx, int time) -> int {
            if (idx == n) return 0;
            if (dp[idx][time] != -1) return dp[idx][time];
            if (satisfaction[idx] >= 0) return dp[idx][time] = satisfaction[idx] * time + rec(idx + 1, time + 1);
            int take, notTake;
            take = satisfaction[idx] * time + rec(idx + 1, time + 1);
            notTake = rec(idx + 1, time);
            return dp[idx][time] = max(take, notTake);
        };

        return rec(0, 1);
    }
};