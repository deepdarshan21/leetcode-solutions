#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        auto dfs = [&](auto dfs, int i, int j, int ocn) {
            // cout<<ocn<<" - "<<i<<" "<<j<<endl;
            if (ocn == 0) {
                if (i == 0 or j == 0) return true;
                // if (i == (n - 1) or j == (m - 1)) return false;
            }
            if (ocn == 1) {
                if (i == (n - 1) or j == (m - 1)) return true;
                // if (i == 0 or j == 0) return false;
            }
            if (heights[i][j] == -1) return false;
            int tmp = heights[i][j];
            bool res = false;
            heights[i][j] = -1;
            // cout<<"check"<<endl;
            if (i < (n - 1) && tmp >= heights[i + 1][j]) res |= dfs(dfs, i + 1, j, ocn);
            if (j < (m - 1) && tmp >= heights[i][j + 1]) res |= dfs(dfs, i, j + 1, ocn);
            if (i > 0 && tmp >= heights[i - 1][j]) res |= dfs(dfs, i - 1, j, ocn);
            if (j > 0 && tmp >= heights[i][j - 1]) res |= dfs(dfs, i, j - 1, ocn);
            heights[i][j] = tmp;
            return res;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout<<"Start"<<i<<" "<<j<<endl;
                if (dfs(dfs, i, j, 0) && dfs(dfs, i, j, 1)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};