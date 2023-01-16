#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Prefix Sum

   Edge Cases:

   Time Complexity: O(n*m) Space: O(n*m)
   Status:
   Runtime: 466 ms faster than: 56.43%
   Memory Usage: 142.6 MB less than: 22.41%
   Remarks:
*/

class NumMatrix {
   private:
    vector<vector<int>> dp;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = matrix[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
    }
};