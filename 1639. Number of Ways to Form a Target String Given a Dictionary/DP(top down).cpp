#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        check for every possible condition

   Edge Cases:

   Time Complexity: O(m*n*(m*len)) Space: O(n*len)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = words[0].size(), len = target.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(len, -1));

        auto help = [&](auto self, int k, int i) {
            if (i >= len) return 1;
            if (k >= n) return 0;
            if (dp[k][i] != -1) return dp[k][i];
            int res = 0;
            for (int j = 0; j < m; j++) {
                for (int idx = k; idx < n; idx++) {
                    if (target[i] == words[j][idx]) {
                        res = (res + self(self, idx + 1, i + 1)) % mod;
                    }
                }
            }
            return dp[k][i] = res;
        };

        return help(help, 0, 0);
    }
};