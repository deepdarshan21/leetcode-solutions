#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.2 MB less than: 90.23%
   Remarks:
*/

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        int i = 0, j = 0;
        while (j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
            if (i == s.size()) {
                return true;
            }
        }
    }
};