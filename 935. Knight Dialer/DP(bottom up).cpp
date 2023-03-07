#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP (bottom up)
        Use a 2d vector to store the number of ways to reach a number from a
        previous number. The number of ways to reach a number from a previous number
        is the sum of the number of ways to reach the previous number from the
        previous previous number.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 186 ms faster than: 60%
   Memory Usage: 37.3 MB less than: 42%
   Remarks:
*/

class Solution {
   public:
    int knightDialer(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> help = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4},
        };
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k : help[j]) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[n][i]) % mod;
        }
        return ans;
    }
};