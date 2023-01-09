#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS + DP

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 203 ms faster than: 73.1%
   Memory Usage: 53.2 MB less than: 49.97%
   Remarks:
*/

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        unordered_map<int, bool> dp;
        vector<int> safeNodes;
        auto dfs = [&](auto dfs, int i) {
            if (dp.find(i) != dp.end()) return dp[i];
            if (visited[i]) return false;
            if (graph[i].size() == 0) return true;
            bool res = true;
            visited[i] = true;
            for (int j = 0; j < graph[i].size(); j++) {
                if (!dfs(dfs, graph[i][j])) {
                    res = false;
                    break;
                }
            }
            visited[i] = false;
            return dp[i] = res;
        };
        // for (int i = 0; i < n; i++) {
        //     if (graph[i].size() == 0) terminalNodes.insert(i);
        // }
        for (int i = 0; i < n; i++) {
            if (dfs(dfs, i)) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};