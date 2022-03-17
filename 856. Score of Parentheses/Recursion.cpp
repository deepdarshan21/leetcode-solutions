#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion, Brute Force
        Make possible pairs of parentheses and find the value of them

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 5 ms faster than: 14.59%
   Memory Usage: 6.2 MB less than: 8.12%
   Remarks:
*/

class Solution {
   public:
    int scoreOfParentheses(string s) {
        return recursion(s, 0, s.size());
    }

   private:
    int recursion(string s, int start, int end) {
        int ans = 0, isClosing = 0;
        for (int i = start; i < end; i++) {
            isClosing += s[i] == '(' ? 1 : -1;
            if (!isClosing) {
                if (i - start == 1) {
                    ans++;
                } else {
                    ans += (2 * recursion(s, start + 1, i));
                }
                start = i + 1;
            }
        }
        return ans;
    }
};