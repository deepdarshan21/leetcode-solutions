#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Timit Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = 0;
        return help(prices, dp, 0, fee);
    }
    int help(vector<int> &prices, vector<int> &dp, int start, int fee) {
        if (start == prices.size()) return 0;
        if (dp[start] != INT_MIN) return dp[start];
        int res = help(prices, dp, start + 1, fee);
        for (int i = start; i < prices.size(); i++) {
            res = max(res, prices[i] - prices[start] - fee + help(prices, dp, i + 1, fee));
        }
        dp[start] = res;
        return res;
    }
};