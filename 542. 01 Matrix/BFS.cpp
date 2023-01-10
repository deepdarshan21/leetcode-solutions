#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n*m) Space: O(n)
   Status: Accepted
   Runtime: 98 ms faster than: 70.83%
   Memory Usage: 30.3 MB less than: 60.15%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i = tmp.first + dir[k][0], j = tmp.second + dir[k][1];
                if (i >= 0 && j >= 0 && i < n && j < m) {
                    if (res[i][j] > (res[tmp.first][tmp.second] + 1)) {
                        res[i][j] = res[tmp.first][tmp.second] + 1;
                        q.push({i, j});
                    }
                }
            }
        }
        return res;
    }
};