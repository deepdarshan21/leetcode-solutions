#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for every possible combinations

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0, maxAvl;
        for (int i = 0; i < prices.size(); i++) {
            maxAvl = INT_MIN;
            for (int j = i + 1; j < prices.size(); j++) {
                if (maxAvl < prices[j] && prices[j] > prices[i]) {
                    maxAvl = prices[j];
                }
            }
            if (maxDiff < (maxAvl - prices[i])) {
                maxDiff = maxAvl - prices[i];
            }
        }
        return maxDiff;
    }
};