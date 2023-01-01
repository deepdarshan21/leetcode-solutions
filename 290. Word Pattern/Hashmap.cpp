#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashmap

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.4 MB less than: 82.12%
   Remarks:
*/

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        for (auto x : s) {
            if (x == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        words.push_back(word);
        if (words.size() != pattern.size()) return false;
        int n = pattern.size();
        unordered_map<char, string> mp1;
        for (int i = 0; i < n; i++) {
            if (mp1[pattern[i]] == "") {
                mp1[pattern[i]] = words[i];
            } else {
                if (mp1[pattern[i]] != words[i]) return false;
            }
        }
        unordered_map<string, char> mp2;
        for (int i = 0; i < n; i++) {
            if (mp2.find(words[i]) == mp2.end()) {
                mp2[words[i]] = pattern[i];
            } else {
                if (mp2[words[i]] != pattern[i]) return false;
            }
        }
        return true;
    }
};