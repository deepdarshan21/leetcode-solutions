#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(Using LCS)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 231 ms faster than: 35.20%
   Memory Usage: 74 MB less than: 12.84%
   Remarks:
*/

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string rev(s.begin(), s.end());
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto rec = [&](auto rec, int i, int j) {
            if (i == n || j == n) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            if (s[i] == rev[j]) return dp[i][j] = rec(rec, i + 1, j + 1) + 1;
            return dp[i][j] = max(rec(rec, i + 1, j), rec(rec, i, j + 1));
        };
        return rec(rec, 0, 0);
    }
};