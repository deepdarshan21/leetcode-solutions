#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)
        Check all possible combinations of P, L, A
        Use 3D dp array to store the result of each subproblem
        dp[i][j][k] = number of ways to make attendance record of length i with j absent and k late

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 2289 ms faster than: 13.38%
   Memory Usage: 394.9 MB less than: 19.8%
   Remarks:
*/

class Solution {
   public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        auto rec = [&](auto &&self, int n, int allowedAbsent, int allowedLate) {
            if (n == 0) return 1;
            if (dp[n][allowedAbsent][allowedLate] != -1) return dp[n][allowedAbsent][allowedLate];

            int res = 0;
            if (allowedAbsent > 0) res = (res + self(self, n - 1, allowedAbsent - 1, 2)) % mod;
            if (allowedLate > 0) res = (res + self(self, n - 1, allowedAbsent, allowedLate - 1)) % mod;
            res = (res + self(self, n - 1, allowedAbsent, 2)) % mod;
            dp[n][allowedAbsent][allowedLate] = res;
            return res;
        };
        return rec(rec, n, 1, 2) % mod;
    }
};