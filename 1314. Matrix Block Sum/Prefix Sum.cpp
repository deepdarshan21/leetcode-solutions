#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Prefix Sum

   Edge Cases:

   Time Complexity: O(n*m) Space: O(n*m)
   Status: Accepted
   Runtime: 11 ms faster than: 78.59%
   Memory Usage: 9.5 MB less than: 41.46%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = mat[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k);
                r1++;
                c1++;
                r2++;
                c2++;
                mat[i][j] = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
            }
        }
        return mat;
    }
};