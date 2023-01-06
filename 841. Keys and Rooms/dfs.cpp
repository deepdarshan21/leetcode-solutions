#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 12 ms faster than: 77%
   Memory Usage: 10.6 MB less than: 31%
   Remarks:
*/

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 1) return true;
        vector<int> vis(n, 0);
        auto dfs = [&](auto dfs, int start) {
            if (vis[start] == 1) return false;
            vis[start] = 1;
            int check = accumulate(vis.begin(), vis.end(), 0);
            if (check == n) return true;
            int m = rooms[start].size();
            for (int i = 0; i < m; i++) {
                if (dfs(dfs, rooms[start][i])) return true;
            }
            return false;
        };
        return dfs(dfs, 0);
    }
};