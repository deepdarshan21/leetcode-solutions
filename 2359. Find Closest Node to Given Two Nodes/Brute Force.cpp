#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS from both nodes and find the node with the maximum distance from both nodes


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 266 ms faster than: 61.77%
   Memory Usage: 100.1 MB less than: 67.59%
   Remarks:
*/

class Solution {
   public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        queue<int> q;
        q.push(node1);
        dist1[node1] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            // cout<<edges[curr]<<endl;
            if (edges[curr] != -1 && dist1[edges[curr]] == -1) {
                dist1[edges[curr]] = dist1[curr] + 1;
                q.push(edges[curr]);
            }
        }
        q.push(node2);
        dist2[node2] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (edges[curr] != -1 && dist2[edges[curr]] == -1) {
                dist2[edges[curr]] = dist2[curr] + 1;
                q.push(edges[curr]);
            }
        }
        int ans = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            // cout<<dist1[i]<<" "<<dist2[i]<<endl;
            if (dist1[i] != -1 && dist2[i] != -1 && max(dist1[i], dist2[i]) <= minDist) {
                if (max(dist1[i], dist2[i]) == minDist && i > ans) continue;
                minDist = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};