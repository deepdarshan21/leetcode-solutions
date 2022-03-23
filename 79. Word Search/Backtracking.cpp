#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> store;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j]) {
                    store.push_back({i, j});
                    if (backtrack(board, word, 1, i + 1, j, store) || backtrack(board, word, 1, i - 1, j, store) || backtrack(board, word, 1, i, j + 1, store) || backtrack(board, word, 1, i, j - 1, store)) {
                        return true;
                    }
                    store.pop_back();
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string word, int curr, int i, int j, vector<pair<int, int>> store) {
        if (curr == word.size()) {
            return true;
        }
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
            if (word[curr] == board[i][j]) {
                if (find(store.begin(), store.end(), make_pair(i, j)) == store.end()) {
                    store.push_back({i, j});
                    return backtrack(board, word, curr + 1, i + 1, j, store) || backtrack(board, word, curr + 1, i - 1, j, store) || backtrack(board, word, curr + 1, i, j + 1, store) || backtrack(board, word, curr + 1, i, j - 1, store);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};