#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dp(top down)

   Edge Cases:

   Time Complexity: O(n*minProfit*m*2) Space: O(n*minProfit*m)
   Status: Accepted
   Runtime: 508 ms faster than: 8.96%
   Memory Usage: 54 MB less than: 20.28%
   Remarks:
*/

class Solution {
   public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        int mod = 1e9 + 7, res = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(minProfit + 1, vector<int>(m, -1)));

        auto help = [&](auto self, int currProfit, int currN, int idx) {
            if (currN > n) return 0;
            if (idx >= m && currProfit >= minProfit) return 1;
            if (idx >= m) return 0;
            if (dp[currN][currProfit][idx] != -1) return dp[currN][currProfit][idx];
            int res1 = 0, res2 = 0;
            res1 = (self(self, currProfit, currN, idx + 1)) % mod;
            // currProfit += profit[idx];
            // currN += group[idx];
            res2 = (self(self, min(currProfit + profit[idx], minProfit), currN + group[idx], idx + 1)) % mod;
            if (idx == 2) {
                cout << currProfit << " " << currN << endl;
            }
            return dp[currN][currProfit][idx] = (res1 + res2) % mod;
        };
        return help(help, 0, 0, 0);
    }
};