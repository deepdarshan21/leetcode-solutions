#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP (bottom up)


   Edge Cases:

   Time Complexity: O(nsqrt(n)) Space: O(n)
   Status: Accepted
   Runtime: 35 ms faster than: 89.7%
   Memory Usage: 6.3 MB less than: 87.85%
   Remarks:
*/

class Solution {
   public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};