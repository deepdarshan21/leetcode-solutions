#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n*m) Space: O(n*m)
   Status: Accepted
   Runtime: 213 ms faster than: 14.9%
   Memory Usage: 17.6 MB less than: 76.6%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> alt(n, vector<bool>(m, false));
        vector<vector<int>> res;
        auto dfs = [&](auto dfs, vector<vector<bool>>& ocn, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || heights[i][j] == -1) return false;
            if (ocn[i][j]) return true;
            int tmp = heights[i][j];
            bool res = false;
            heights[i][j] = -1;
            if (i < (n - 1) && tmp >= heights[i + 1][j]) res |= dfs(dfs, ocn, i + 1, j);
            if (j < (m - 1) && tmp >= heights[i][j + 1]) res |= dfs(dfs, ocn, i, j + 1);
            if (i > 0 && tmp >= heights[i - 1][j]) res |= dfs(dfs, ocn, i - 1, j);
            if (j > 0 && tmp >= heights[i][j - 1]) res |= dfs(dfs, ocn, i, j - 1);
            heights[i][j] = tmp;
            ocn[i][j] = res;
            return res;
        };
        for (int i = 0; i < n; i++) {
            pac[i][0] = true;
            alt[i][m - 1] = true;
        }
        for (int i = 0; i < m; i++) {
            pac[0][i] = true;
            alt[n - 1][i] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(dfs, pac, i, j) && dfs(dfs, alt, i, j)) res.push_back({i, j});
            }
        }
        return res;
    }
};