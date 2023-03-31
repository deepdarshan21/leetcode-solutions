#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(m*n*k*(m+n)) Space: O(m*n*k)
   Status: Accepted
   Runtime: 22 ms faster than: 84.82%
   Memory Usage: 8.6 MB less than: 23.4%
   Remarks:
*/

class Solution {
   public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        int mod = 1e9 + 7;
        vector<vector<int>> preSum(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                preSum[i][j] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0);
            }
        }

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k)));
        // function<int(int, int, int)> rec = [&](int idx, int jdx, int c) -> int {
        //     if (preSum[idx][jdx] == 0) return 0;
        //     if (c == 0) return 1;
        //     if (dp[idx][jdx][c] != -1) return dp[idx][jdx][c];
        //     int res = 0;
        //     for (int i = idx + 1; i < n; i++) {
        //         if (preSum[idx][jdx] - preSum[i][jdx] > 0) {
        //             res = (res + rec(i, jdx, c - 1)) % mod;
        //         }
        //     }
        //     for (int j = jdx + 1; j < m; j++) {
        //         if (preSum[idx][jdx] - preSum[idx][j] > 0) {
        //             res = (res + rec(idx, j, c - 1)) % mod;
        //         }
        //     }
        //     return dp[idx][jdx][c] = res;
        // };
        // return rec(0, 0, k - 1);
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) dp[i][j][0] = 1;
        }
        for (int idx = n; idx >= 0; idx--) {
            for (int jdx = m; jdx >= 0; jdx--) {
                if (preSum[idx][jdx] == 0) dp[idx][jdx][0] = 0;
                for (int c = 1; c < k; c++) {
                    if (preSum[idx][jdx] == 0)
                        dp[idx][jdx][k] = 0;
                    else {
                        int res = 0;
                        for (int i = idx + 1; i < n; i++) {
                            if (preSum[idx][jdx] - preSum[i][jdx] > 0) {
                                res = (res + dp[i][jdx][c - 1]) % mod;
                            }
                        }
                        for (int j = jdx + 1; j < m; j++) {
                            if (preSum[idx][jdx] - preSum[idx][j] > 0) {
                                res = (res + dp[idx][j][c - 1]) % mod;
                            }
                        }
                        dp[idx][jdx][c] = res;
                    }
                }
            }
        }
        return dp[0][0][k - 1];
    }
};