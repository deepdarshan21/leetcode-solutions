#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: 201/214
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, -1));
        auto help = [&](auto help, int buyAt, int transactionLeft) {
            if (transactionLeft == 0 || buyAt >= (n - 1)) return 0;
            if (dp[transactionLeft - 1][buyAt] != -1) return dp[transactionLeft - 1][buyAt];
            int profit = 0;
            for (int i = buyAt + 1; i < n; i++) {
                if (prices[i] > prices[buyAt]) {
                    profit = max(profit, prices[i] - prices[buyAt]);
                    for (int j = i + 1; j < n; j++) {
                        profit = max(profit, prices[i] - prices[buyAt] + help(help, j, transactionLeft - 1));
                    }
                }
            }
            return dp[transactionLeft - 1][buyAt] = profit;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, help(help, i, 2));
        }
        return res;
    }
};