#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Answer is good but it will not find the unique substrings
*/

class Solution {
   public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();

        function<char(char)> nextChar = [&](char ch) {
            if (ch == 'z') return 'a';
            return char(ch + 1);
        };

        int res = 1, start = 0;
        for (int i = 1; i < n; i++) {
            if (nextChar(s[i - 1]) == s[i])
                res += (i - start + 1);
            else {
                res += 1;
                start = i;
            }
        }

        return res;
    }
};