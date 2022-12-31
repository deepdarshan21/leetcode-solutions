#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        Same as previous question with only diffence that at obstracle path will be 0

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 67%
   Memory Usage: 7.9 MB less than: 15%
   Remarks:
*/

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        auto rec = [&](auto rec, int i, int j) {
            // recursive function
            if (dp[i][j] != -1) return dp[i][j];
            if (obstacleGrid[i][j] == 1) return 0;
            if (i == (m - 1) && j == (n - 1)) return 1;
            if (i == (m - 1)) return dp[i][j] = rec(rec, i, j + 1);
            if (j == (n - 1)) return dp[i][j] = rec(rec, i + 1, j);
            return dp[i][j] = rec(rec, i + 1, j) + rec(rec, i, j + 1);
        };
        return rec(rec, 0, 0);
    }
};