#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP
        Create 4 variables to store the max profit of 2 transactions
        buy1: the min price to buy the first stock
        sell1: the max profit to sell the first stock
        buy2: the min price to buy the second stock
        sell2: the max profit to sell the second stock
        Iterate through the prices array, update the 4 variables
        return sell2

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 157 ms faster than: 87.30%
   Memory Usage: 75.2 MB less than: 89.85%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = INT_MAX, buy2 = INT_MAX, sell1 = 0, sell2 = 0;
        for (int i = 0; i < n; i++) {
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - sell1);
            sell2 = max(sell2, prices[i] - buy2);
        }
        return sell2;
    }
};