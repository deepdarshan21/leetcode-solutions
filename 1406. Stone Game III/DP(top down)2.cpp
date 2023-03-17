#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        Use prefix sum to calculate the score of each player.
        dp[i] = max(prefixSum[i] - dp[i + 1], prefixSum[i] - dp[i + 2], prefixSum[i] - dp[i + 3])

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 368 ms faster than: 16.92%
   Memory Usage: 166.2 MB less than: 12.31%
   Remarks:
*/

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        vector<int> dp(n, -1);

        auto rec = [&](auto self, int idx) -> int {
            if (idx >= n) return 0;
            if (dp[idx] != -1) return dp[idx];
            int a = INT_MAX, b = INT_MAX, c = INT_MAX;
            a = self(self, idx + 1);
            if (idx + 1 < n) b = self(self, idx + 2);
            if (idx + 2 < n) c = self(self, idx + 3);
            return dp[idx] = prefixSum[n] - prefixSum[idx] - min({a, b, c});
        };

        int tmp = rec(rec, 0);

        if (tmp > prefixSum[n] - tmp)
            return "Alice";
        else if (tmp == prefixSum[n] - tmp)
            return "Tie";
        else
            return "Bob";
    }
};