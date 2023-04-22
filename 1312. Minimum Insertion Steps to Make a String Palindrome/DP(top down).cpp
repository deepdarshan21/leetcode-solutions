#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 86 ms faster than: 48.33%
   Memory Usage: 28.6 MB less than: 24.45%
   Remarks:
*/

class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        auto help = [&](auto self, int idx, int jdx) {
            if (idx > jdx) return 0;
            if (dp[idx][jdx] != -1) return dp[idx][jdx];
            if (s[idx] == s[jdx]) return dp[idx][jdx] = self(self, idx + 1, jdx - 1);
            return dp[idx][jdx] = min(self(self, idx + 1, jdx), self(self, idx, jdx - 1)) + 1;
        };

        return help(help, 0, n - 1);
    }
};