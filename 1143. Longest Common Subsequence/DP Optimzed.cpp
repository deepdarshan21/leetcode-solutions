#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 100 ms faster than: 5.11%
   Memory Usage: 20.1 MB less than: 6.29%
   Remarks:
*/

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        auto help = [&](auto help, int i, int j) {
            if (i == n1 || j == n2) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            if (text1[i] == text2[j]) return dp[i][j] = help(help, i + 1, j + 1) + 1;
            return dp[i][j] = max(help(help, i + 1, j), help(help, i, j + 1));
        };
        return help(help, 0, 0);
    }
};