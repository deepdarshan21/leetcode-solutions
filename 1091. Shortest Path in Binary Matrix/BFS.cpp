#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 129 ms faster than: 53.13%
   Memory Usage: 32.1 MB less than: 22.92%
   Remarks:
*/

class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n - 1][n - 1] != 0) return -1;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q, qTemp;
        int steps = 0;
        q.push({0, 0});
        while (!q.empty()) {
            steps++;
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i == (n - 1) && j == (n - 1)) return steps;
                if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] == 1) continue;
                vis[i][j] = true;
                qTemp.push({i + 1, j});
                qTemp.push({i - 1, j});
                qTemp.push({i, j + 1});
                qTemp.push({i, j - 1});
                qTemp.push({i + 1, j + 1});
                qTemp.push({i + 1, j - 1});
                qTemp.push({i - 1, j + 1});
                qTemp.push({i - 1, j - 1});
            }
            swap(q, qTemp);
        }
        return -1;
    }
};