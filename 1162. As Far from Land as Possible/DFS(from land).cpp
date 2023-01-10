#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(m*n*n) Space: O(m*n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = -1;
        int n = grid.size(), m = grid[0].size();
        auto dfs = [&](auto dfs, int i, int j, int dist) {
            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0 || grid[i][j] <= dist) return;
            grid[i][j] = dist;
            dfs(dfs, i + 1, j, dist + 1);
            dfs(dfs, i - 1, j, dist + 1);
            dfs(dfs, i, j + 1, dist + 1);
            dfs(dfs, i, j - 1, dist + 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    dfs(dfs, i, j, 1);
                }
                if (grid[i][j] > 1) res = max(res, grid[i][j] - 1);
            }
        }
        return res;
    }
};