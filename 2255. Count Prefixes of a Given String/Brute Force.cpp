#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n*m) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 97.38%
   Memory Usage: 12 MB less than: 27.78%
   Remarks:
*/

class Solution {
   public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            int m = words[i].size();
            if (words[i] == s.substr(0, m)) count++;
        }
        return count;
    }
};