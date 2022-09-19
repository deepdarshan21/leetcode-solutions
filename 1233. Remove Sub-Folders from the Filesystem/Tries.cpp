#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 606 ms faster than: 20.58%
   Memory Usage: 183.6 MB less than: 13.56%
   Remarks:
*/

class Solution {
   private:
    class Trie {
       public:
        Trie* child[27];
        string word;
        Trie() {
            word = "";
            for (int i = 0; i < 27; i++) {
                child[i] = nullptr;
            }
        }
    };
    void insert(Trie* root, string str) {
        int idx;
        for (char x : str) {
            if (idx == '/')
                idx = 26;
            else
                idx = x - 97;
            if (root->child[idx] != nullptr) {
                root->child[idx] = new Trie();
            }
            root = root->child[idx];
        }
        root->word = str;
    }
    void print(Trie* root, vector<string>& res) {
        if (root == nullptr) return;
        if (root->word != "") {
            res.push_back(root->word);
            if (root->child[26] != nullptr) return;
        }
        for (int i = 0; i < 27; i++) {
            if (root->child[i] == nullptr) continue;
            print(root->child[i], res);
        }
    }

   public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = nullptr;
        for (int i = 0; i < folder.size(); i++) {
            insert(root, folder[i]);
        }
        vector<string> res;
        print(root, res);
        return res;
    }
};