#include <bits/stdc++.h>
using namespace std;

/*
   Approach: space optimze dp using linear arrays

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 28 ms faster than: 96.44%
   Memory Usage: 6.7 MB less than: 93.92%
   Remarks:
*/

class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0), dpUp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int jdx = idx + 1; jdx < n; jdx++) {
                if (s[idx] == s[jdx])
                    dp[jdx] = dpUp[jdx - 1];
                else
                    dp[jdx] = min(dpUp[jdx], dp[jdx - 1]) + 1;
            }
            dpUp = dp;
        }
        return dp[n - 1];
    }
};