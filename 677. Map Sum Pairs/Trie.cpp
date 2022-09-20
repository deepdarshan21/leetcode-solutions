#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 10 ms faster than: 17.37%
   Memory Usage: 8.2 MB less than: 34.62%
   Remarks:
*/

class MapSum {
   public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        insert1(root, key, val);
    }

    int sum(string prefix) {
        return search(root, prefix);
    }

   private:
    class TrieNode {
       public:
        unordered_map<char, TrieNode *> child;
        int val;
        TrieNode() {
            val = 0;
        }
    };
    TrieNode *root;

    void insert1(TrieNode *root, string key, int val) {
        for (char x : key) {
            if (root->child[x] == nullptr)
                root->child[x] = new TrieNode();
            root = root->child[x];
        }
        root->val = val;
    }
    int search(TrieNode *root, string prefix) {
        for (char x : prefix) {
            if (root->child[x] == nullptr)
                return 0;
            root = root->child[x];
        }
        return help(root);
    }
    int help(TrieNode *root) {
        if (root == nullptr) return 0;
        int sum = 0;
        sum += root->val;
        for (auto itr : root->child) {
            sum += help(itr.second);
        }
        return sum;
    }
};