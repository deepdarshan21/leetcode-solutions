#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 91.06%
   Memory Usage: 13.1 MB less than: 47.39%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int res = 0, temp;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};