#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int integerBreak(int n) {
        vector<int> dp(n, -1);
        auto help = [&](auto help, int t) {
            if (t == 1) return dp[t - 1] = 1;
            if (dp[t - 1] != -1) return dp[t - 1];
            int num1 = max(t / 2, help(help, t / 2));
            int num2 = max(t - t / 2, help(help, t - t / 2));
            return dp[t - 1] = num1 * num2;
        };
        return help(help, n);
    }
};