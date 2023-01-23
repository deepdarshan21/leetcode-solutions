#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 150 ms faster than: 41.27%
   Memory Usage: 14.5 MB less than: 59.95%
   Remarks:
*/

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int maxVal = 1e4 + 1;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, maxVal);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                } else
                    break;
            }
        }
        return (dp[amount] == maxVal) ? -1 : dp[amount];
    }
};