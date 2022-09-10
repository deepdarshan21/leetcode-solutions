#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Check for every posibility


   Edge Cases:

   Time Complexity: O(n^k) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            profit = max(profit, sell(k, prices, n, i));
        }
        return profit;
    }

   private:
    int sell(int k, vector<int> prices, int n, int buy) {
        if (k == 0 || buy == (n - 1)) {
            return 0;
        }
        int curr_profit = 0, next_max_profit = 0, max_profit = 0;
        for (int i = buy + 1; i < n; i++) {
            curr_profit = prices[i] - prices[buy];
            if (curr_profit == 0) continue;
            next_max_profit = 0;
            for (int j = i + 1; j < n; j++) {
                next_max_profit = max(next_max_profit, sell(k - 1, prices, n, j));
            }
            max_profit = max(max_profit, curr_profit + next_max_profit);
        }
        return max_profit;
    }
};