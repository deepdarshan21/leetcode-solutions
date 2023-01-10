#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS(First find rowNo and colNo of each island and then find the min distance)

   Edge Cases:

   Time Complexity: O(n*m*n) Space: O(n*m)
   Status: Accepted
   Runtime: 413 ms faster than: 16.74%
   Memory Usage: 23.4 MB less than: 32.78%
   Remarks:
*/

class Solution {
   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> island1, island2;
        int res = INT_MAX;
        auto dfs = [&](auto dfs, int i, int j, vector<pair<int, int>>& island) {
            if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return;
            grid[i][j] = -1;
            island.push_back({i, j});
            dfs(dfs, i + 1, j, island);
            dfs(dfs, i - 1, j, island);
            dfs(dfs, i, j + 1, island);
            dfs(dfs, i, j - 1, island);
        };
        int no = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (no == 1)
                        dfs(dfs, i, j, island1);
                    else if (no == 2)
                        dfs(dfs, i, j, island2);
                    no++;
                }
            }
        }
        for (int i = 0; i < island1.size(); i++) {
            int x1 = island1[i].first, y1 = island1[i].second;
            for (int j = 0; j < island2.size(); j++) {
                int x2 = island2[j].first, y2 = island2[j].second;
                res = min(res, abs(x1 - x2) + abs(y1 - y2));
            }
        }
        return res - 1;
    }
};