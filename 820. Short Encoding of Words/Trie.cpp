#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie
    Reverse the words for and then put that in string and if in trie we need to create new branch then
    return the size of word plus one or else how many level you go down

   Edge Cases:

   Time Complexity: O(n*m) Space: O(m*n)
   Status: Accepted
   Runtime: 52 ms faster than: 89.63%
   Memory Usage: 74 MB less than: 22.56%
   Remarks:
*/

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int res = 0;
        for (string word : words) {
            res += help(root, word);
        }
        return res;
    }

   private:
    class TrieNode {
       public:
        TrieNode* child[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    int help(TrieNode* root, string str) {
        int n = str.size();
        int count = 0, idx;
        bool newLevel = false, newBranch = false;
        for (int i = n - 1; i >= 0; i--) {
            newLevel = true;
            for (int j = 0; j < 26; j++)
                if (root->child[j] != nullptr) {
                    newLevel = false;
                    break;
                }
            idx = str[i] - 97;
            if (root->child[idx] == nullptr) {
                root->child[idx] = new TrieNode();
                if (!newLevel)
                    newBranch = true;
                else
                    count++;
            }
            root = root->child[idx];
        }
        return newBranch ? str.size() + 1 : count;
    }
};