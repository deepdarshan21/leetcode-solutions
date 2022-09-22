#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 282 ms faster than: 91.01%
   Memory Usage: 79.3 MB less than: 29.37%
   Remarks:
*/

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) insert(root, num);
        int res = 0;
        for (int num : nums) res = max(res, maxXOR(root, num));
        return res;
    }

   private:
    class TrieNode {
       public:
        TrieNode* child[2];
        int val;
        TrieNode() {
            val = 0;
            child[0] = child[1] = nullptr;
        }
    };
    void insert(TrieNode* root, int val) {
        for (int i = 31; i >= 0; i--) {
            int idx = (val >> i) & 1;
            if (root->child[idx] == nullptr) {
                root->child[idx] = new TrieNode();
            }
            root = root->child[idx];
        }
        root->val = val;
    }
    int maxXOR(TrieNode* root, int val) {
        for (int i = 31; i >= 0; i--) {
            int idx = (val >> i) & 1;
            if (root->child[1 - idx] != nullptr)
                root = root->child[1 - idx];
            else
                root = root->child[idx];
        }
        return root->val ^ val;
    }
};