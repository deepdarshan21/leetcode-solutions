#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> safeNodes;
        auto dfs = [&](auto dfs, int i) {
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
            return res;
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