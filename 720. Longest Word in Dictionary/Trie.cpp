#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 101 ms faster than: 49.92%
   Memory Usage: 24.4 MB less than: 63.39%
   Remarks:
*/

class Solution {
   public:
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        sort(words.begin(), words.end());
        int maxLen = 0;
        string res = "";
        for (string word : words) {
            if (help(root, word)) {
                if (word.length() > maxLen) {
                    maxLen = word.length();
                    res = word;
                }
            }
        }
        return res;
    }

   private:
    class TrieNode {
       public:
        TrieNode* child[26];
        bool end;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            end = false;
        }
    };
    bool help(TrieNode* root, string word) {
        bool res = false;
        if (word.size() == 1) {
            char x = word[0];
            if (root->child[x - 97] == nullptr) {
                res = true;
                root->child[x - 97] = new TrieNode();
            }
            root = root->child[x - 97];
            root->end = true;
            return res;
        }
        for (char x : word) {
            if (root->child[x - 97] == nullptr) {
                root->child[x - 97] = new TrieNode();
                if (res) return false;
                if (!res && root->end) res = true;
            }
            root = root->child[x - 97];
            if (!res && !root->end) return false;
        }
        root->end = true;
        return res;
    }
};