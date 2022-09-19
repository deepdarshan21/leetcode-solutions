#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Trie

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 198 ms faster than: 55.60%
   Memory Usage: 72.7 MB less than: 48.70%
   Remarks:
*/

class Solution {
   private:
    class Trie {
       public:
        Trie* child[26];
        string word;
        Trie() {
            word = "";
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    void insert(Trie* root, string str) {
        for (char x : str) {
            if (root->child[x - 97] == nullptr)
                root->child[x - 97] = new Trie();
            root = root->child[x - 97];
        }
        root->word = str;
    }
    string search(Trie* root, string str) {
        for (char x : str) {
            if (root->word != "") break;
            if (root->child[x - 97] == nullptr) return "";
            root = root->child[x - 97];
        }
        return root->word;
    }

   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (string str : dictionary) {
            insert(root, str);
        }
        vector<string> store;
        string temp = "";
        for (char x : sentence) {
            if (x == ' ') {
                store.push_back(temp);
                temp = "";
            } else
                temp += x;
        }
        store.push_back(temp);
        string res = "";
        for (string str : store) {
            temp = search(root, str);
            if (temp == "")
                res += str;
            else
                res += temp;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};