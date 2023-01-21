#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP Bottom Up

   Edge Cases:

   Time Complexity: O(n1*n2) Space: O(n1*n2)
   Status: Accepted
   Runtime: 43 ms faster than: 25.23%
   Memory Usage: 18.7 MB less than: 10.19%
   Remarks:
*/

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    if (text1[i - 1] == text2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};