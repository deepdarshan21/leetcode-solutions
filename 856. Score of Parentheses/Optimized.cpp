#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force(Optimized)


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:
   Runtime: 2 ms faster than: 37.38%
   Memory Usage: 6 MB less than: 83.25%
   Remarks:
*/

class Solution {
   public:
    int scoreOfParentheses(string s) {
        int res = 0, bal = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i - 1] == '(') {
                    res += pow(2, bal);
                }
            }
        }
        return res;
    }
};