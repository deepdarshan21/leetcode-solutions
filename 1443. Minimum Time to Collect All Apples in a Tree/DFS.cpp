#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS
        First create graph and then traverse depth first search

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 181 ms faster than: 93.29%
   Memory Usage: 60.4 MB less than: 93.96%
   Remarks:
*/

class Solution {
   public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> gh(n);
        vector<bool> vis(n, false);
        auto dfs = [&](auto dfs, int vtx) {
            int res = 0, tmp;
            if (vis[vtx]) return -1;
            if (gh[vtx].size() == 0 && !hasApple[vtx]) return -1;
            vis[vtx] = true;
            for (int i = 0; i < gh[vtx].size(); i++) {
                tmp = dfs(dfs, gh[vtx][i]);
                if (tmp != -1) res += tmp + 2;
            }
            if (res == 0 && !hasApple[vtx]) return -1;
            return res;
        };
        for (int i = 0; i < edges.size(); i++) {
            gh[edges[i][0]].push_back(edges[i][1]);
            gh[edges[i][1]].push_back(edges[i][0]);
        }
        int res = dfs(dfs, 0);
        if (res == -1) return 0;
        return res;
    }
};