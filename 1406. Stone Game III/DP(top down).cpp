#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 811 ms faster than: 5.23%
   Memory Usage: 239.8 MB less than: 5.23%
   Remarks:
*/

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<long long>> dp(n, vector<long long>(2, LLONG_MAX));

        auto rec = [&](auto self, int idx, int turn) -> int {
            if (idx >= n) return 0;
            if (dp[idx][turn] != LLONG_MAX) return dp[idx][turn];
            int score = 0, bestMax = INT_MIN, bestMin = INT_MAX;
            for (int i = 0; i < 3 && idx + i < n; i++) {
                if (turn == 0) {
                    score += stoneValue[idx + i];
                    bestMax = max(bestMax, score + self(self, idx + i + 1, 1 - turn));
                } else {
                    score -= stoneValue[idx + i];
                    bestMin = min(bestMin, score + self(self, idx + i + 1, 1 - turn));
                }
            }
            return dp[idx][turn] = turn == 0 ? bestMax : bestMin;
        };

        int tmp = rec(rec, 0, 0);
        if (tmp > 0)
            return "Alice";
        else if (tmp == 0)
            return "Tie";
        else
            return "Bob";
    }
};