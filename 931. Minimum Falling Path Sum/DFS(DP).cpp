#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS(DP)

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n*n)
   Status: Accepted
   Runtime: 16 ms faster than: 80.26%
   Memory Usage: 10.3 MB less than: 20.24%
   Remarks:
*/

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = INT_MAX;
        auto dfs = [&](auto dfs, int i, int j) {
            if (dp[i][j] != -1) return dp[i][j];
            if (i == (n - 1)) return dp[i][j] = matrix[i][j];
            int tmp1, tmp2, tmp3;
            tmp1 = tmp2 = tmp3 = INT_MAX;
            tmp1 = dfs(dfs, i + 1, j);
            if (j > 0) tmp2 = dfs(dfs, i + 1, j - 1);
            if (j < (n - 1)) tmp3 = dfs(dfs, i + 1, j + 1);
            int tmp = min({tmp1, tmp2, tmp3}) + matrix[i][j];
            return dp[i][j] = tmp;
        };
        for (int i = 0; i < n; i++) res = min(res, dfs(dfs, 0, i));
        return res;
    }
};