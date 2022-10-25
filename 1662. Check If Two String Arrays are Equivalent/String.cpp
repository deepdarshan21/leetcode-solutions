#include <bits/stdc++.h>
using namespace std;

/*
   Approach: String

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 13 ms faster than: 21.77%
   Memory Usage: 11.7 MB less than: 27.24%
   Remarks:
*/

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for (string word : word1) s1 += word;
        for (string word : word2) s2 += word;
        return s1 == s2;
    }
};