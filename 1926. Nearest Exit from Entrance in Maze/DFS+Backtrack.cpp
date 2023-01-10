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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int res = INT_MAX;
        auto dfs = [&](auto dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m) return 0;
            if (maze[i][j] == 'v' || maze[i][j] == '+') return INT_MAX;
            maze[i][j] = 'v';
            int tmp = INT_MAX;
            tmp = min(tmp, dfs(dfs, i + 1, j));
            tmp = min(tmp, dfs(dfs, i - 1, j));
            tmp = min(tmp, dfs(dfs, i, j + 1));
            tmp = min(tmp, dfs(dfs, i, j - 1));
            if (tmp == INT_MAX) return INT_MAX;
            return tmp + 1;
        };
        int start = entrance[0], end = entrance[1];
        if (start > 0) res = min(res, dfs(dfs, start - 1, end));
        if (start < (n - 1)) res = min(res, dfs(dfs, start + 1, end));
        if (end > 0) res = min(res, dfs(dfs, start, end - 1));
        if (end < (m - 1)) res = min(res, dfs(dfs, start, end + 1));
        if (res == INT_MAX) return -1;
        return res;
    }
};