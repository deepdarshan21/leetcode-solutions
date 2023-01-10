#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = INT_MAX, tmp = INT_MAX;
        auto dfs = [&](auto dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1) return INT_MAX;
            if (grid[i][j] == 1) return 0;
            int res = INT_MAX;
            grid[i][j] = -1;
            res = min(res, dfs(dfs, i + 1, j));
            res = min(res, dfs(dfs, i - 1, j));
            res = min(res, dfs(dfs, i, j + 1));
            res = min(res, dfs(dfs, i, j - 1));
            grid[i][j] = 0;
            if (res == INT_MAX) return INT_MAX;
            return res + 1;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    cout << i << " " << j << endl;
                    if ((i + 1) < n and grid[i + 1][j] == 0) tmp = dfs(dfs, i + 1, j);
                    res = min(res, tmp);
                    cout << "i+1 " << res << endl;
                    if ((i - 1) >= 0 and grid[i - 1][j] == 0) tmp = dfs(dfs, i - 1, j);
                    res = min(res, tmp);
                    cout << "i-1 " << tmp << endl;
                    if ((j + 1) < m and grid[i][j + 1] == 0) tmp = dfs(dfs, i, j + 1);
                    res = min(res, tmp);
                    cout << "j+1 " << tmp << endl;
                    if ((j - 1) >= 0 and grid[i][j - 1] == 0) tmp = dfs(dfs, i, j - 1);
                    res = min(res, tmp);
                    cout << "j-1 " << tmp << endl;
                    grid[i][j] = 1;
                }
            }
        }
        return res;
    }
};