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
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), res = 0;
        vector<int> dp(n, 0);
        int start = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if (dp[i] < (values[i] - i)) {
                dp[i] = values[i] - i;
                continue;
            }
            if (values[i] >= values[start]) start = i;
        }
        res = values[start] + start + dp[n - 1];
        return res;
    }
};