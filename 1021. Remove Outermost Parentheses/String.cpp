#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string res = "";
        for (char x : s) {
            if (x == '(') {
                if (open > 0) res += x;
                open++;
            } else {
                open--;
                if (open > 0) res += x;
            }
        }
        return res;
    }
};