#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: We are here running loop everytime ye get water and it repeats intself
*/

class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        auto dfs = [&](auto dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= grid.size() || j > grid[0].size() || grid[i][j] == -1) return INT_MAX;
            if (grid[i][j] == 1) return 0;
            grid[i][j] = -1;
            int tmp = INT_MAX;
            tmp = min(tmp, dfs(dfs, i + 1, j));
            tmp = min(tmp, dfs(dfs, i - 1, j));
            tmp = min(tmp, dfs(dfs, i, j + 1));
            tmp = min(tmp, dfs(dfs, i, j - 1));
            if (tmp == INT_MAX) return tmp;
            return tmp + 1;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    res = max(res, dfs(dfs, i, j));
                }
            }
        }
        if (res == 0) return -1;
        return res;
    }
};