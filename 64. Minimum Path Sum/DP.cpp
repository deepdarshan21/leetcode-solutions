#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        Similar to previous one with only difference that now we need to return min sum

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 9 ms faster than: 86.94%
   Memory Usage: 10.4 MB less than: 6.80%
   Remarks:
*/

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        auto rec = [&](auto rec, int i, int j) {
            // recursive function
            if (dp[i][j] != -1) return dp[i][j];
            if (i == (m - 1) && j == (n - 1)) return dp[i][j] = grid[i][j];
            if (i == (m - 1)) return dp[i][j] = grid[i][j] + rec(rec, i, j + 1);
            if (j == (n - 1)) return dp[i][j] = grid[i][j] + rec(rec, i + 1, j);
            return dp[i][j] = grid[i][j] + min(rec(rec, i + 1, j), rec(rec, i, j + 1));
        };
        return rec(rec, 0, 0);
    }
};