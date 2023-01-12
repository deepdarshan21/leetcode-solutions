#include <bits/stdc++.h>
using namespace std;

/*
   Approach:DFS

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> gh(n);
        vector<int> res(n, 0);
        vector<bool> vis(n, false);
        auto dfs = [&](auto dfs, int i, vector<int> arr) {
            if (i < 0 || i >= n || vis[i]) return;
            vis[i] = true;
            for (int itr : arr) {
                if (labels[i] == labels[itr]) res[itr]++;
            }
            for (int itr : gh[i]) {
                arr.push_back(itr);
                dfs(dfs, itr, arr);
                arr.pop_back();
            }
        };
        for (vector<int> edge : edges) {
            gh[edge[0]].push_back(edge[1]);
            gh[edge[1]].push_back(edge[0]);
        }
        dfs(dfs, 0, {0});
        return res;
    }
};