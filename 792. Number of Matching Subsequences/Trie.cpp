#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        TrieNode* root = new TrieNode();
        insert(root, s);
        int count = 0;
        for (string word : words)
            if (isSubsequence(root, word)) count++;
        return count;
    }

   private:
    class TrieNode {
       public:
        TrieNode* child[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };
    void insert(TrieNode* root, string str) {
        for (char x : str) {
            if (root->child[x - 97] == nullptr)
                root->child[x - 97] = new TrieNode();
            root = root->child[x - 97];
        }
    }
    bool isSubsequence(TrieNode* root, string word) {
        int i = 0, n = word.size();
        while (i < n && !root) {
            if (root->child[word[i] - 97] != nullptr) {
                i++;
                root = root->child[word[i] - 97];
            } else {
                bool flag = true;
                for (int j = 0; j < 26; j++) {
                    if (root->child[j] != nullptr) {
                        root = root->child[j];
                        flag = false;
                        break;
                    }
                }
                if (flag) root = nullptr;
            }
        }
        return i == n;
    }
};