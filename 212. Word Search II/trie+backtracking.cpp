#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie + DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 1668 ms faster than: 34.88%
   Memory Usage: 15.5 MB less than: 30.86%
   Remarks:
*/

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root;
        root = new TrieNode();
        for (string word : words) insert(word, root);
        vector<string> res;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(board, i, j, root, res);
        return res;
    }

   private:
    class TrieNode {
       public:
        unordered_map<char, TrieNode*> child;
        bool isEnd;
        string word;
        TrieNode() {
            isEnd = false;
            word = "";
        }
    };

    void insert(string word, TrieNode*& root) {
        TrieNode* curr = root;
        for (char x : word) {
            if (curr->child.find(x) == curr->child.end())
                curr->child[x] = new TrieNode();
            curr = curr->child[x];
        }
        curr->isEnd = true;
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* start, vector<string>& res) {
        // DFS
        char ch = board[i][j];
        if (ch == '#' || start->child.find(ch) == start->child.end()) return;
        start = start->child[ch];
        if (start->isEnd) {
            res.push_back(start->word);
            start->isEnd = false;
            start->word = "";
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, start, res);
        if (j > 0) dfs(board, i, j - 1, start, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, start, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, start, res);
        board[i][j] = ch;
    }
};