#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 15 ms faster than: 78%
   Memory Usage: 9.4 MB less than: 71%
   Remarks:
*/

class Solution {
   public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && dfs(grid, i, j)) res++;
            }
        }
        return res;
    }
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0) return true;
        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) return false;
        grid[i][j] = -1;
        bool res = true;
        res &= dfs(grid, i + 1, j);
        if (!res) return res;
        res &= dfs(grid, i - 1, j);
        if (!res) return res;
        res &= dfs(grid, i, j + 1);
        if (!res) return res;
        res &= dfs(grid, i, j - 1);
        return res;
    }
};