#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
    Create a image of word in binay form which will help afterward in finding is there exist a letter common or not.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 202 ms faster than: 45.47%
   Memory Usage: 24.6 MB less than: 31.21%
   Remarks:
*/

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> binaryWords;
        for (string word : words) {
            binaryWords.push_back(0);
            for (char ch : word) {
                binaryWords.back() = binaryWords.back() | (int)pow(2, (int)ch - 97);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((binaryWords[i] & binaryWords[j]) == 0) res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};