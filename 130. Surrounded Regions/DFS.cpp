#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS
        Start from every corner

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 15 ms faster than: 74.63%
   Memory Usage: 10.2 MB less than: 53.34%
   Remarks:
*/

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        auto dfs = [&](auto dfs, int i, int j) {
            if (i < 0 || j < 0 || i == m || j == n || board[i][j] != 'O') return;
            board[i][j] = 'V';
            dfs(dfs, i + 1, j);
            dfs(dfs, i - 1, j);
            dfs(dfs, i, j + 1);
            dfs(dfs, i, j - 1);
        };
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(dfs, i, 0);
            if (board[i][n - 1] == 'O') dfs(dfs, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(dfs, 0, j);
            if (board[m - 1][j] == 'O') dfs(dfs, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }
};