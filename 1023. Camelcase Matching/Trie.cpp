#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 57.01%
   Memory Usage: 9.3 MB less than: 5.35%
   Remarks:
*/

class Solution {
   public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TrieNode* root = new TrieNode();
        vector<bool> res;
        for (string query : queries) {
            insert(root, query);
            res.push_back(match(root, query, pattern));
        }
        return res;
    }

   private:
    class TrieNode {
       public:
        unordered_map<char, TrieNode*> child;
        TrieNode(){};
    };
    void insert(TrieNode* root, string str) {
        for (char x : str) {
            if (root->child[x] == nullptr) {
                root->child[x] = new TrieNode();
            }
            root = root->child[x];
        }
    }
    bool match(TrieNode* root, string str, string pattern) {
        int i = 0;
        for (char x : str) {
            if (!(pattern[i] < 97 && x > 96) && (i >= pattern.size() || (pattern[i] < 97 && x < 97 && x != pattern[i]) || root->child[x] == nullptr)) {
                return false;
            }
            root = root->child[x];
            if (pattern[i] == x) i++;
        }
        if (i < pattern.size()) return false;
        return true;
    }
};