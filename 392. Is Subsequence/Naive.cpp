#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 240 ms faster than: 5.04%
   Memory Usage: 6.4 MB less than: 33.59%
   Remarks:
*/

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (t.size() < s.size()) {
            return false;
        }
        for (int i = 0; i <= t.size() - s.size(); i++) {
            int j = i, k = 0;
            while (true) {
                if (k == s.size()) {
                    return true;
                }
                if (j == t.size()) {
                    break;
                }
                if (t[j] == s[k]) {
                    j++;
                    k++;
                } else {
                    j++;
                }
            }
        }
        return false;
    }
};