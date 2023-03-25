#include <bits/stdc++.h>
using namespace std;

/*
   Approach: No. of groups in graph

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 662 ms faster than: 51.622%
   Memory Usage: 210.6 MB less than: 24.27%
   Remarks:
*/

class Solution {
   public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gh(n);
        for (auto e : edges) {
            gh[e[0]].push_back(e[1]);
            gh[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, false);
        int tmp = 0;
        auto dfs = [&](auto self, int idx) {
            if (vis[idx]) return;
            tmp += 1;
            vis[idx] = true;
            for (int itr : gh[idx]) self(self, itr);
        };

        long long res = 0;
        long long prev = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
                res += (tmp - prev) * (n - tmp);
                prev = tmp;
            }
        }

        return res;
    }
};