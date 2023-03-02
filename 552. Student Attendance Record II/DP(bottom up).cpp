#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        dp[i][j][k] = number of ways to have i days, j absent, k late
        dp[i][j][k] = dp[i - 1][j][2] + dp[i - 1][j - 1][2] + dp[i - 1][j][k - 1]

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 1866 ms faster than: 25.63%
   Memory Usage: 385.4 MB less than: 26.53%
   Remarks:
*/

class Solution {
   public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                dp[0][i][j] = 1;
            }
        }

        for (int numDays = 1; numDays <= n; numDays++) {
            for (int numAbsent = 0; numAbsent < 2; numAbsent++) {
                for (int numLate = 0; numLate < 3; numLate++) {
                    int res = 0;
                    if (numAbsent > 0) res = (res + dp[numDays - 1][numAbsent - 1][2]) % mod;
                    if (numLate > 0) res = (res + dp[numDays - 1][numAbsent][numLate - 1]) % mod;
                    res = (res + dp[numDays - 1][numAbsent][2]) % mod;
                    dp[numDays][numAbsent][numLate] = res;
                }
            }
        }

        return dp[n][1][2];
    }
};