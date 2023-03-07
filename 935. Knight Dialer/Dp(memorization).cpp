#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization (dp)
        Use a 2d vector to store the number of ways to reach a number from a
        previous number. The number of ways to reach a number from a previous number
        is the sum of the number of ways to reach the previous number from the
        previous previous number.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 320 ms faster than: 24%
   Memory Usage: 40.2 MB less than: 37%
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
        vector<vector<int>> dp(n, vector<int>(10, -1));
        auto rec = [&](auto rec, int n, int prev) -> int {
            if (n == 0) return 1;
            if (dp[n][prev] != -1) return dp[n][prev];  // memorization (dp
            int ans = 0;
            for (int i : help[prev]) {
                ans = (ans + rec(rec, n - 1, i)) % mod;
            }
            return dp[n][prev] = ans;
        };
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + rec(rec, n - 1, i)) % mod;
        }
        return ans;
    }
};