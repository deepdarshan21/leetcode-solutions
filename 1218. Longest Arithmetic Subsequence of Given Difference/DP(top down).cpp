#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, -1);

        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            if (dp[idx] != -1) return dp[idx];
            for (int i = idx; i < n; i++) {
                if ((arr[i] - arr[idx - 1]) == difference) {
                    return dp[idx] = 1 + self(self, i + 1);
                }
            }
            return dp[idx] = 0;
        };
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, 1 + rec(rec, i));
        }
        return ans;
    }
};