#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> gh;
        int u, v, dist;
        for (auto e : edgeList) {
            u = e[0];
            v = e[1];
            dist = e[2];
            gh[u].push_back({v, dist});
            gh[v].push_back({u, dist});
        }
        auto help = [&](int p, int q, int limit) {
            vector<bool> vis(n, false);
            queue<int> que;
            que.push(p);
            vis[p] = true;
            int u, v, dist;
            while (!que.empty()) {
                u = que.front();
                vis[u] = true;
                if (u == q) return true;
                que.pop();
                for (auto itr : gh[u]) {
                    v = itr.first;
                    dist = itr.second;
                    if (!vis[v] && dist < limit) que.push(v);
                }
            }
            return false;
        };
        vector<bool> res;
        for (auto itr : queries) {
            res.push_back(help(itr[0], itr[1], itr[2]));
        }
        return res;
    }
};