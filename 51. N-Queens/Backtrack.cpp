#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtrack

   Edge Cases:

   Time Complexity: O(n^n) Space: O(1)
   Status: Accepted
   Runtime: 14 ms faster than: 34.25%
   Memory Usage: 7.4 MB less than: 47.93%
   Remarks:
*/

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return ans;
    }

   private:
    vector<vector<string>> ans;
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        int i, j;
        i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row, j = col;
        while (i < n && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j++;
        }
        i = row, j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        i = row, j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            if (isSafe(board, row, i)) {
                board[row][i] = 'Q';
                backtrack(board, row + 1);
                board[row][i] = '.';
            }
        }
    }
};