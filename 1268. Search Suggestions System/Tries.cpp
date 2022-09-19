#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie
    Use trie to first store the element then search the elements


   Edge Cases:

   Time Complexity: O(m) Space: O(n*m)
   Status: Accepted
   Runtime: 2256 ms faster than: 5.01%
   Memory Usage: 611.9 MB less than: 11.19%
   Remarks:
*/

class Solution {
   private:
    class TrieNode {
       public:
        bool is_end;
        string word;
        TrieNode* child[26];
        TrieNode() {
            bool is_end = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            word = "";
        }
    };
    void insert(TrieNode* root, string str) {
        TrieNode* curr = root;
        for (char x : str) {
            if (curr->child[x - 97] == nullptr) {
                curr->child[x - 97] = new TrieNode();
            }
            curr = curr->child[x - 97];
        }
        curr->is_end = true;
        curr->word = str;
    }

    vector<string> search(TrieNode* root, string str) {
        TrieNode* curr = root;
        vector<string> res;
        for (char x : str) {
            if (curr->child[x - 97] == nullptr) return res;
            curr = curr->child[x - 97];
        }
        // cout<<"check2"<<endl;

        vector<string> temp = suggest(curr);
        int n = min(int(temp.size()), 3);
        for (int i = 0; i < n; i++) {
            res.push_back(temp[i]);
        }
        return res;
    }
    vector<string> suggest(TrieNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        // cout<<root->word<<endl;
        if (root->word != "") {
            res.push_back(root->word);
        }
        TrieNode* temp = root;
        for (int i = 0; i < 26; i++) {
            if (temp->child[i] == nullptr) continue;
            vector<string> tmp = suggest(temp->child[i]);
            int n = min(3 - res.size(), tmp.size());
            for (int i = 0; i < n; i++) {
                res.push_back(tmp[i]);
            }
            // cout<<"check3"<<endl;
            if (res.size() >= 3) {
                return res;
            }
        }
        return res;
    }

   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < products.size(); i++) {
            insert(root, products[i]);
        }
        // cout<<"check"<<endl;
        vector<vector<string>> res;
        string temp = "";
        for (char x : searchWord) {
            temp += x;
            res.push_back(search(root, temp));
            // cout<<"check1"<<endl;
        }
        return res;
    }
};