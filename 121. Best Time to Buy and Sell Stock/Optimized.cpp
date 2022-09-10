#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Max difference


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:  Accepted
   Runtime: 274 ms faster than: 14.23%
   Memory Usage: 93.4 MB less than: 51.70%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(), buy = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < prices[buy])
                buy = i;
            else
                profit = max(profit, prices[i] - prices[buy]);
        }
        return profit;
    }
};