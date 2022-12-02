#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS
    First make all the edge land water and edge connected land water and then count remaining lands inside


   Edge Cases:

   Time Complexity: O(n*m) Space: O(1)
   Status: Accepted
   Runtime: 185 ms faster than: 27.39%
   Memory Usage: 29.3 MB less than: 58.72%
   Remarks:
*/

class Solution {
   public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && ((i * j) == 0 || i == (n - 1) || j == (m - 1))) dfs(grid, i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout<<grid[i][j]<<" ";
                if (grid[i][j] == 1) res++;
            }
            // cout<<endl;
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // cout<<i<<" "<<j<<endl;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 0;
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
    }
};