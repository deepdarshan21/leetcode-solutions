#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 161 ms faster than: 64.34%
   Memory Usage: 53 MB less than: 28.78%
   Remarks:
*/

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < (n - 1)) return -1;
        vector<vector<int>> gh(n);
        vector<bool> vis(n, false);
        int isLand = 0;
        auto dfs = [&](auto dfs, int i) {
            if (i < 0 || i >= n || vis[i]) return;
            vis[i] = true;
            for (int j = 0; j < gh[i].size(); j++) dfs(dfs, gh[i][j]);
        };
        for (int i = 0; i < m; i++) {
            gh[connections[i][0]].push_back(connections[i][1]);
            gh[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
                isLand++;
            }
        }
        return isLand - 1;
    }
};