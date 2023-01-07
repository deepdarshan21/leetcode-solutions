#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Graph(Adjacency Matrix) DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 27 ms faster than: 79.60%
   Memory Usage: 13.6 MB less than: 98.89%
   Remarks:
*/

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int res = 0;
        auto dfs = [&](auto dfs, int i) {
            if (i < 0 || i >= n || vis[i]) return;
            vis[i] = true;
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && !vis[j]) dfs(dfs, i);
            }
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
                res++;
            }
        }
        return res;
    }
};