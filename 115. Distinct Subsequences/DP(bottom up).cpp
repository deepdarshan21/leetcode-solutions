#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(knapsack)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 95 ms faster than: 19%
   Memory Usage: 19 MB less than: 47%
   Remarks:
*/

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto rec = [&](auto self, int i, int j) -> int {
            if (j == m) return 1;
            if (i == n) return 0;

            if (dp[i][j] != -1) return dp[i][j];
            int take = 0, notTake = 0;
            if (s[i] == t[j]) {
                take = self(self, i + 1, j + 1);
            }
            notTake = self(self, i + 1, j);
            return dp[i][j] = take + notTake;
        };

        return rec(rec, 0, 0);
    }
};