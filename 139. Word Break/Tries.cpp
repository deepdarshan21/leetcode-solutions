#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization and DP

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 12 ms faster than: 67%
   Memory Usage: 10 MB less than: 56%
   Remarks:
*/

class Solution {
   private:
    class Trie {
       public:
        unordered_map<char, Trie*> child;
        bool isEnd;

        Trie() {
            isEnd = false;
        }
    };
    void insert(Trie* root, string word) {
        if (root == nullptr) return;
        for (char x : word) {
            if (root->child.find(x) == root->child.end()) {
                root->child[x] = new Trie();
            }
            root = root->child[x];
        }
        root->isEnd = true;
    }

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        for (string word : wordDict) insert(root, word);
        vector<int> dp(s.size(), -1);
        return dfs(root, s, dp, 0);
    }
    bool dfs(Trie* root, string& s, vector<int>& dp, int idx) {
        if (idx >= s.size()) return true;
        if (dp[idx] != -1) return dp[idx];
        Trie* temp = root;
        bool tmp = false;
        for (int i = idx; i < s.size(); i++) {
            if (temp->child.find(s[i]) == temp->child.end()) return dp[idx] = false;
            temp = temp->child[s[i]];
            if (temp->isEnd == true) tmp = dfs(root, s, dp, i + 1);
            if (tmp) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
};