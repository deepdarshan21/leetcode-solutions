#include <bits/stdc++.h>
using namespace std;

/*
   Approach: For a valid, openCount==closeCount

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 40.84%
   Memory Usage: 6.7 MB less than: 95.93%
   Remarks:
*/

class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0, openCount = 0, closeCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                openCount++;
            else
                closeCount++;
            if (closeCount > openCount) {
                openCount = 0;
                closeCount = 0;
            }
            if (closeCount == openCount) res = max(res, closeCount * 2);
        }
        openCount = closeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(')
                openCount++;
            else
                closeCount++;
            if (closeCount < openCount) {
                openCount = 0;
                closeCount = 0;
            }
            if (closeCount == openCount) res = max(res, closeCount * 2);
        }
        return res;
    }
};