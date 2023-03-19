#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class WordDictionary {
   public:
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* curr = root;
        for (char x : word) {
            if (curr->child[x] == nullptr) {
                curr->child[x] = new Trie();
            }
            curr = curr->child[x];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        // unordered_map<string, bool> ump;
        // if (ump.find(word) != ump.end()) return ump[word];
        return helper(root, word, 0);
        // return ump[word];
    }

   private:
    class Trie {
       public:
        unordered_map<char, Trie*> child;
        bool isEnd;
        Trie() {
            isEnd = false;
        }
    };
    Trie* root;
    bool helper(Trie* root, string& word, int idx) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto ch : root->child) {
                    if (helper(ch.second, word, i + 1)) return true;
                    return false;
                }
                if (root->child[word[i]] == nullptr) return false;
                root = root->child[word[i]];
            }
        }
        return root->isEnd;
    }
};