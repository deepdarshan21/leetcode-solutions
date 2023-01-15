#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS(DP)

   Edge Cases:

   Time Complexity: O(n) Space: O(n*n)
   Status: Accepted
   Runtime: 10 ms faster than: 4966%
   Memory Usage: 9.2 MB less than: 5.74%
   Remarks:
*/

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto dfs = [&](auto dfs, int i, int j) {
            if (dp[i][j] != -1) return dp[i][j];
            if (i == (n - 1)) return dp[i][j] = triangle[i][j];
            int tmp1 = dfs(dfs, i + 1, j);
            int tmp2 = dfs(dfs, i + 1, j + 1);
            return dp[i][j] = min(tmp1, tmp2) + triangle[i][j];
        };
        return dfs(dfs, 0, 0);
    }
};