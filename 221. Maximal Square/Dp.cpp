#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 106 ms faster than: 54.52%
   Memory Usage: 21 MB less than: 20.94%
   Remarks:
*/

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = max(res, 1);
            }
            if (matrix[i][m - 1] == '1') {
                dp[i][m - 1] = 1;
                res = max(res, 1);
            }
        }
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                res = max(res, 1);
            }
            if (matrix[n - 1][j] == '1') {
                dp[n - 1][j] = 1;
                res = max(res, 1);
            }
        }
        // main code
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') continue;
                int tmp = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                dp[i][j] = tmp + 1;
                res = max(res, dp[i][j] * dp[i][j]);
            }
        }
        return res;
    }
};