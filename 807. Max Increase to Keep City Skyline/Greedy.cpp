#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 13 ms faster than: 73.35%
   Memory Usage: 10 MB less than: 72.36%
   Remarks:
*/

class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n), col(n);
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) temp = max(temp, grid[i][j]);
            col[i] = temp;
        }
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) temp = max(temp, grid[j][i]);
            row[i] = temp;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) res += min(row[j], col[i]) - grid[i][j];
        }
        return res;
    }
};