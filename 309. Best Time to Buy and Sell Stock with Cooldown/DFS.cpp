#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 24.69%
   Memory Usage: 12 MB less than: 36.50%
   Remarks:
*/

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(prices, dp, 0, true);
    }
    int dfs(vector<int> &prices, vector<vector<int>> &dp, int i, bool buy) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int res = 0;
        if (buy)
            res = max(res, -prices[i] + dfs(prices, dp, i + 1, !buy));
        else
            res = max(res, prices[i] + dfs(prices, dp, i + 2, !buy));
        res = max(res, dfs(prices, dp, i + 1, buy));
        return dp[i][buy] = res;
    }
};