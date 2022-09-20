#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 113 ms faster than: 46.57%
   Memory Usage: 43.5 MB less than: 83.94%
   Remarks:
*/

class Trie {
   private:
    class TrieNode {
       public:
        unordered_map<char, TrieNode*> child;
        bool isEnd;
        TrieNode() {
            isEnd = false;
        }
    };
    TrieNode* root;

   public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char x : word) {
            if (curr->child[x] == nullptr)
                curr->child[x] = new TrieNode();
            curr = curr->child[x];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char x : word) {
            if (curr->child[x] == nullptr)
                return false;
            curr = curr->child[x];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char x : prefix) {
            if (curr->child[x] == nullptr)
                return false;
            curr = curr->child[x];
        }
        return true;
    }
};