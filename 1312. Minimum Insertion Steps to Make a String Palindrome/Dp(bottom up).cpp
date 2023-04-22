#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 54 ms faster than: 73.79%
   Memory Usage: 28.4 MB less than: 50.59%
   Remarks:
*/

class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // auto help = [&](auto self, int idx, int jdx) {
        //     if (idx > jdx) return 0;
        //     if (dp[idx][jdx] != -1) return dp[idx][jdx];
        //     if (s[idx] == s[jdx]) return dp[idx][jdx] = self(self, idx + 1, jdx - 1);
        //     return dp[idx][jdx] = min(self(self, idx + 1, jdx), self(self, idx, jdx - 1)) + 1;
        // };

        // return help(help, 0, n - 1);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int jdx = idx + 1; jdx < n; jdx++) {
                if (s[idx] == s[jdx])
                    dp[idx][jdx] = dp[idx + 1][jdx - 1];
                else
                    dp[idx][jdx] = min(dp[idx + 1][jdx], dp[idx][jdx - 1]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};