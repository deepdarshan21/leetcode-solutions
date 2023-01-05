#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtracking

   Edge Cases:

   Time Complexity: O(n!) Space: O(logn)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        auto backtrack = [&](auto backtrack, int i) {
            if (i >= n) return 1;
            if (s[i] == '0') return -1;
            int res = 0, tmp1 = 0, tmp2 = 0;
            string temp = "";
            tmp1 = backtrack(backtrack, i + 1);
            if (tmp1 < 0) tmp1 = 0;
            if ((i + 1) < n) {
                temp += s[i];
                temp += s[i + 1];
                if (stoi(temp) <= 26) {
                    tmp2 = backtrack(backtrack, i + 2);
                    if (tmp2 < 0) tmp2 = 0;
                }
            }
            return tmp1 + tmp2;
        };
        int res = backtrack(backtrack, 0);
        if (res == -1) return 0;
        return res;
    }
};