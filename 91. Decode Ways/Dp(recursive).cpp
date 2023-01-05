#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dynamic Programming

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.2 MB less than: 48%
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        auto backtrack = [&](auto backtrack, int i) {
            if (i >= n) return 1;
            if (s[i] == '0') return -1;
            if (dp[i] != -1) return dp[i];
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
            return dp[i] = tmp1 + tmp2;
        };
        if (s[0] == '0') return 0;
        return backtrack(backtrack, 0);
    }
};