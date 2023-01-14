#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 724 ms faster than: 75.51%
   Memory Usage: 172.6 MB less than: 50.59%
   Remarks:
*/

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> gh(n);
        for (vector<int> edge : edges) {
            gh[edge[0]].push_back(edge[1]);
            gh[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(source);
        vis[source] = true;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int i = 0; i < gh[tmp].size(); i++) {
                if (gh[tmp][i] == destination) return true;
                if (vis[gh[tmp][i]]) continue;
                q.push(gh[tmp][i]);
                vis[gh[tmp][i]] = true;
            }
        }
        return false;
    }
};