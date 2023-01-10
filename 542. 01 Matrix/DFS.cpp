#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        auto dfs = [&](auto dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == -1) return INT_MAX;
            if (res[i][j] != -1) return res[i][j];
            int tmp = mat[i][j];
            if (tmp == 0) return res[i][j] = 0;
            mat[i][j] = -1;
            int temp = INT_MAX;
            temp = min(temp, dfs(dfs, i + 1, j));
            temp = min(temp, dfs(dfs, i - 1, j));
            temp = min(temp, dfs(dfs, i, j + 1));
            temp = min(temp, dfs(dfs, i, j - 1));
            mat[i][j] = tmp;
            cout << i << " " << j << " " << temp + 1 << endl;
            return res[i][j] = temp + 1;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(dfs, i, j);
                cout << i << " " << j << endl;
            }
        }
        return res;
    }
};