#include <bits/stdc++.h>
using namespace std;

/*
   Approach: dfs

   Edge Cases:

   Time Complexity: O(N) Space: O(1)
   Status: Accepted
   Runtime: 36 ms faster than: 60.98%
   Memory Usage: 23.3 MB less than: 66.91%
   Remarks:
*/

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return 0;
        int res = 1;
        grid[i][j] = -1;
        res += dfs(grid, i + 1, j);
        res += dfs(grid, i - 1, j);
        res += dfs(grid, i, j + 1);
        res += dfs(grid, i, j - 1);
        return res;
    }
};