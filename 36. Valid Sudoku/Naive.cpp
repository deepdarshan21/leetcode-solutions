#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for every element

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 27 ms faster than: 68.55%
   Memory Usage: 20.03 MB less than: 27.80%
   Remarks:
*/

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row wise check
        for (auto row : board) {
            unordered_map<char, bool> check;
            for (auto element : row) {
                if (element != '.') {
                    if (check[element] == true) {
                        return false;
                    }
                    check[element] = true;
                }
            }
        }
        // column wise check
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> check;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (check[board[j][i]] == true) {
                        return false;
                    }
                    check[board[j][i]] = true;
                }
            }
        }
        unordered_map<char, bool> check;
        // box 1
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 2
        for (int i = 3; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 3
        for (int i = 6; i < 9; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 4
        for (int i = 0; i < 3; i++) {
            for (int j = 3; j < 6; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 5
        for (int i = 3; i < 6; i++) {
            for (int j = 3; j < 6; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 6
        for (int i = 6; i < 9; i++) {
            for (int j = 3; j < 6; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 7
        for (int i = 0; i < 3; i++) {
            for (int j = 6; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 8
        for (int i = 3; i < 6; i++) {
            for (int j = 6; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        // box 9
        for (int i = 6; i < 9; i++) {
            for (int j = 6; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]] == true) {
                        return false;
                    }
                    check[board[i][j]] = true;
                }
            }
        }
        check.clear();
        return true;
    }
};