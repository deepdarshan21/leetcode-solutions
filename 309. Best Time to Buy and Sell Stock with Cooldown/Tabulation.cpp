#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 69%
   Memory Usage: 11 MB less than: 99.96%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int rest = 0, buy = -prices[0], sell = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int temp = rest;
            rest = max(rest, sell);
            buy = max(buy, temp - prices[i]);
            sell = buy + prices[i];
        }
        return max(sell, rest);
    }
};