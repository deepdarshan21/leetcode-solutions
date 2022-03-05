#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 5 ms faster than: 23.67%
   Memory Usage: 6.4 MB less than: 57.56%
   Remarks:
*/

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int w1 = 0, w2 = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            merged.push_back(word1[w1++]);
            merged.push_back(word2[w2++]);
        }
        if (w1 == word1.size() && w2 < word2.size()) {
            merged += word2.substr(w2);
        }
        if (w2 == word2.size() && w1 < word1.size()) {
            merged += word1.substr(w1);
        }
        return merged;
    }
};