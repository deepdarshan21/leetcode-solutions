#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n) Space: O(n^2)
   Status: Accepted
   Runtime: 91 ms faster than: 45.94%
   Memory Usage: 28.3 MB less than: 5.5%
   Remarks:
*/

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        auto help = [&](auto help, int i, int j) {
            if (i == n && j == m) return true;
            if (i == n && j < m) {
                for (int k = j; k < m; k++) {
                    if (p[k] != '*') return false;
                }
                return true;
            }
            if (i < n && j == m) return false;
            if (dp[i][j] != -1) return dp[i][j] == 1 ? true : false;
            bool res = false;
            if (p[j] == '*') {
                res = help(help, i, j + 1) || help(help, i + 1, j);
            } else if (p[j] == '?' || s[i] == p[j]) {
                res = help(help, i + 1, j + 1);
            } else
                res = false;
            dp[i][j] = res ? 1 : 0;
            return res;
        };
        return help(help, 0, 0);
    }
};