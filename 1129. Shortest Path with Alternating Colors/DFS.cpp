#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n);
        vector<bool> visitedRed(n, false), visitedBlue(n, false);
        unordered_map<int, vector<int>> red, blue;
        // 0: red
        // 1: blue
        auto dfs = [&](auto dfs, int curr, int find, int colour) {
            if (curr == find) return 0;
            if (colour == 0) {
                // segement of RED
                if (visitedRed[curr]) return INT_MAX;
                visitedRed[curr] = true;
                if (red.find(curr) == red.end()) {
                    visitedRed[curr] = false;
                    return INT_MAX;
                }
                int res = INT_MAX, tmp;
                for (int i = 0; i < red[curr].size(); i++) {
                    tmp = dfs(dfs, red[curr][i], find, 1 - colour);
                    if (tmp != INT_MAX) res = min(res, tmp);
                }
                visitedRed[curr] = false;
                if (res == INT_MAX) return INT_MAX;
                return res + 1;
            } else {
                // segement of BLUE
                if (visitedBlue[curr]) return INT_MAX;
                visitedBlue[curr] = true;
                if (blue.find(curr) == blue.end()) {
                    visitedBlue[curr] = false;
                    return INT_MAX;
                }
                int res = INT_MAX, tmp;
                for (int i = 0; i < blue[curr].size(); i++) {
                    tmp = dfs(dfs, blue[curr][i], find, 1 - colour);
                    if (tmp != INT_MAX) res = min(res, tmp);
                }
                visitedBlue[curr] = false;
                if (res == INT_MAX) return INT_MAX;
                return res + 1;
            }
        };
        for (int i = 0; i < redEdges.size(); i++) red[redEdges[i][0]].push_back(redEdges[i][1]);
        for (int i = 0; i < blueEdges.size(); i++) blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        for (int i = 0; i < n; i++) {
            int tmp = INT_MAX;
            tmp = min(tmp, dfs(dfs, 0, i, 0));
            tmp = min(tmp, dfs(dfs, 0, i, 1));
            if (tmp == INT_MAX) tmp = -1;
            res[i] = tmp;
        }
        return res;
    }
};