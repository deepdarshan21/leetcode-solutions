#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Runtime Error(int overflow)
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++) dp[n][m] = 0;
        for (int i = 0; i < n; i++) dp[i][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int take = 0, notTake = 0;
                if (s[i] == t[j]) {
                    take = dp[i + 1][j + 1];
                }
                notTake = dp[i + 1][j];
                dp[i][j] = take + notTake;
            }
        }

        return dp[0][0];
    }
};