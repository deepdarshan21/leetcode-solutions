#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        Implement DP in recursive solution

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.4 MB less than: 52%
   Remarks:
*/

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        auto rec = [&](auto rec, int i, int j) {
            // recursive function
            if (dp[i][j] != -1) return dp[i][j];
            if (i == (m - 1)) return dp[i][j] = 1;
            if (j == (n - 1)) return dp[i][j] = 1;
            return dp[i][j] = rec(rec, i + 1, j) + rec(rec, i, j + 1);
        };
        return rec(rec, 0, 0);
    }
};