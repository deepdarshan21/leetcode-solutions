#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS
        I am using bit mask to avoid visiting a already visited node in a path again
        Using BFS, I will transefer from each node and try to cover hole graph.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status:
   Runtime: 158 ms faster than: 35.25%
   Memory Usage: 18.3 MB less than: 32.98%
   Remarks:
*/

class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int, pair<int, int>>> q;
        // {node, {dist, mask}}
        set<pair<int, int>> vis;
        // {node, mask}
        int n = graph.size();
        int checkPoint = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second.first;
            int mask = q.front().second.second;
            if (mask == checkPoint) return dist;
            q.pop();
            for (int itr : graph[node]) {
                int newMask = (mask | (1 << itr));
                if (vis.find({itr, newMask}) != vis.end()) continue;
                q.push({itr, {dist + 1, newMask}});
                vis.insert({itr, newMask});
            }
        }
        return -1;
    }
};