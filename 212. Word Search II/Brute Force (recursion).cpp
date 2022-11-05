#include <bits/stdc++.h>
using namespace std;

/*
   Approach: For every word find that word exist in matrix or not

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        vector<string> res;
        for (string word : words) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == word[0]) {
                        vector<pair<int, int>> founds;
                        founds.push_back({i, j});
                        if (help(board, word, 1, founds)) {
                            res.push_back(word);
                            found = true;
                        }
                        if (found) break;
                    }
                }
                if (found) break;
            }
        }
        return res;
    }

   private:
    bool help(vector<vector<char>>& board, string word, int idx, vector<pair<int, int>>& founds) {
        int n = board.size(), m = board[0].size(), len = word.size();
        if (idx == len) return true;
        pair<int, int> lastFound = founds.back();
        int i = lastFound.first, j = lastFound.second;
        if ((i + 1) < n && find(founds.begin(), founds.end(), pair<int, int>(i + 1, j)) == founds.end() && word[idx] == board[i + 1][j]) {
            founds.push_back({i + 1, j});
            if (help(board, word, idx + 1, founds))
                return true;
            else
                founds.pop_back();
        }
        if ((j + 1) < m && find(founds.begin(), founds.end(), pair<int, int>(i, j + 1)) == founds.end() && word[idx] == board[i][j + 1]) {
            founds.push_back({i, j + 1});
            if (help(board, word, idx + 1, founds))
                return true;
            else
                founds.pop_back();
        }
        if ((i - 1) >= 0 && find(founds.begin(), founds.end(), pair<int, int>(i - 1, j)) == founds.end() && word[idx] == board[i - 1][j]) {
            founds.push_back({i - 1, j});
            if (help(board, word, idx + 1, founds))
                return true;
            else
                founds.pop_back();
        }
        if ((j - 1) >= 0 && find(founds.begin(), founds.end(), pair<int, int>(i, j - 1)) == founds.end() && word[idx] == board[i][j - 1]) {
            founds.push_back({i, j - 1});
            if (help(board, word, idx + 1, founds))
                return true;
            else
                founds.pop_back();
        }
        return false;
    }
};