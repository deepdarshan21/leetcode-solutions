#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 238 ms faster than: 83.69%
   Memory Usage: 138 MB less than: 28.92%
   Remarks:
*/

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        vector<int> dp(n + 1, -1);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int a = INT_MAX, b = INT_MAX, c = INT_MAX;
            a = dp[i + 1];
            if (i + 1 < n) b = dp[i + 2];
            if (i + 2 < n) c = dp[i + 3];
            dp[i] = prefixSum[n] - prefixSum[i] - min({a, b, c});
        }

        int tmp = dp[0];

        if (tmp > prefixSum[n] - tmp)
            return "Alice";
        else if (tmp == prefixSum[n] - tmp)
            return "Tie";
        else
            return "Bob";
    }
};