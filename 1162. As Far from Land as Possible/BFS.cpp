#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(m*n) Space: O(n)
   Status: Accepted
   Runtime: 113 ms faster than: 56.78%
   Memory Usage: 29.1 MB less than: 17.4%
   Remarks:
*/

class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q, tmpQ;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        }
        int steps = 0;
        while (!q.empty()) {
            steps++;
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0) continue;
                grid[i][j] = steps;
                tmpQ.push({i + 1, j});
                tmpQ.push({i - 1, j});
                tmpQ.push({i, j + 1});
                tmpQ.push({i, j - 1});
            }
            swap(tmpQ, q);
        }
        if (steps == 0 || steps == 1) return -1;
        return steps - 1;
    }
};