#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 711 ms faster than: 24.78%
   Memory Usage: 149 MB less than: 21.73%
   Remarks:
*/

class MagicDictionary {
   public:
    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            insert1(root, word);
        }
    }

    bool search(string searchWord) {
        return search1(root, searchWord, 0, true);
    }

   private:
    class TrieNode {
       public:
        unordered_map<char, TrieNode *> child;
        bool isEnd;
        TrieNode() {
            isEnd = false;
        }
    };
    TrieNode *root;

    void insert1(TrieNode *root, string key) {
        for (char x : key) {
            if (root->child[x] == nullptr)
                root->child[x] = new TrieNode();
            root = root->child[x];
        }
        root->isEnd = true;
    }
    bool search1(TrieNode *root, string &prefix, int idx, bool allowed) {
        if (root == nullptr) {
            return false;
        }
        for (int i = idx; i < prefix.size(); i++) {
            if (allowed) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (search1(root->child[j], prefix, i + 1, prefix[i] == j)) {
                        return true;
                    }
                }
                return false;
            }
            if (root->child[prefix[i]] == nullptr) {
                return false;
            }
            root = root->child[prefix[i]];
        }
        if (root != nullptr && !allowed && root->isEnd) {
            return true;
        }
        return false;
    }
};