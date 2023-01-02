#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS
        for a i, j both grid must be 1

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 358 ms faster than: 78.33%
   Memory Usage: 91 MB less than: 51.38%
   Remarks:
*/

class Solution {
   public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        int res = 0;
        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                if (grid1[i][j] == 1 && grid2[i][j] == 1) {
                    bool check = true;
                    dfs(grid1, grid2, i, j, check);
                    res += check == true ? 1 : 0;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, bool &check) {
        if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || grid2[i][j] != 1) return;
        if (grid1[i][j] != 1) check = false;
        grid2[i][j] = -1;
        dfs(grid1, grid2, i + 1, j, check);
        dfs(grid1, grid2, i - 1, j, check);
        dfs(grid1, grid2, i, j + 1, check);
        dfs(grid1, grid2, i, j - 1, check);
    }
};