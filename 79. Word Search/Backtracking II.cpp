#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtracking
        first find the first letter in the matrix and then check to all of its adjesent sides

   Edge Cases:

   Time Complexity: O(n^3) Space: O(n)
   Status: Accepted
   Runtime: 200 ms faster than: 95.22%
   Memory Usage: 7.8 MB less than: 91.71%
   Remarks:
*/

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if (idx == word.length()) return true;
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = ' ';
        bool found = dfs(board, i + 1, j, idx + 1, word) || dfs(board, i, j + 1, idx + 1, word) || dfs(board, i - 1, j, idx + 1, word) || dfs(board, i, j - 1, idx + 1, word);
        board[i][j] = temp;
        return found;
    }
};