#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Mantain two variables hold and cash

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 169 ms faster than: 85.94%
   Memory Usage: 55.1 MB less than: 76.06%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};