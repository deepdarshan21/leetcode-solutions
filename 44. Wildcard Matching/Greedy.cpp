#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 96.67%
   Memory Usage: 6.6 MB less than: 91.41%
   Remarks:
*/

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0, star = -1, match;
        while (i < n) {
            if (j < m && (s[i] == p[j] or p[j] == '?')) {
                i++;
                j++;
            } else if (j < m and p[j] == '*') {
                star = j++;
                match = i;
            } else if (star != -1) {
                j = star + 1;
                i = ++match;
            } else
                return false;
        }
        while (j < m) {
            if (p[j++] != '*') return false;
        }
        return true;
    }
};