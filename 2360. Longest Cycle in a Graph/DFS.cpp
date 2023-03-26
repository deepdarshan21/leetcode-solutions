#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 214 ms faster than: 66.11%
   Memory Usage: 125.3 MB less than: 54.33%
   Remarks:
*/

class Solution {
   public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, false);
        vector<int> dist(n, 0);
        int res = -1;
        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            int n = edges[node];

            if (n != -1 && !vis[n]) {
                dist[n] = dist[node] + 1;
                dfs(n);
                dist[n] = 0;
            } else if (n != -1 && dist[n] != 0) {
                res = max(res, dist[node] - dist[n] + 1);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dist[i] = 1;
                dfs(i);
                dist[i] = 0;
            }
        }
        return res;
    }
};