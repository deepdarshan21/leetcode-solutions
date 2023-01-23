#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: In line 24 it is not finding the best optimal sol
*/

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        auto help = [&](auto help, int amt, int steps) {
            cout << amt << " " << dp[amt] << endl;
            if (dp[amt] != -1 && dp[amt] < steps) return;
            // if (amt == 0) {
            //     dp[amt] = steps;
            //     return;
            // }
            dp[amt] = steps;
            steps++;
            for (int coin : coins) {
                cout << "check" << endl;
                if ((amt - coin) < 0) return;
                help(help, amt - coin, steps);
            }
        };
        help(help, amount, 0);
        return dp[0];
    }
};