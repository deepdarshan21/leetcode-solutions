#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 320 ms faster than: 7.25%
   Memory Usage: 101.2 MB less than: 5.16%
   Remarks:
*/

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        TrieNode* root = new TrieNode();
        for (int i = 1; i <= n; i++) {
            insert(root, i);
        }
        vector<int> res;
        print(root, res, 0);
        return res;
    }

   private:
    class TrieNode {
       public:
        unordered_map<int, TrieNode*> child;
        TrieNode() {}
    };
    void insert(TrieNode* root, int num) {
        string str = to_string(num);
        for (char x : str) {
            if (root->child[x - 48] == nullptr)
                root->child[x - 48] = new TrieNode();
            root = root->child[x - 48];
        }
    }
    void print(TrieNode* root, vector<int>& res, int num) {
        if (root == nullptr) return;
        for (int i = 0; i < 10; i++) {
            if (root->child[i] == nullptr) continue;
            res.push_back(num * 10 + i);
            print(root->child[i], res, num * 10 + i);
        }
    }
};