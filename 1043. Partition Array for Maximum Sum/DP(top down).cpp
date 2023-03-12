#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dp(top down)

   Edge Cases:

   Time Complexity: O(kn) Space: O(n)
   Status: Accepted
   Runtime: 37 ms faster than: 12.35%
   Memory Usage: 8.8 MB less than: 7.3%
   Remarks:
*/

class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            if (dp[idx] != -1) return dp[idx];
            int ans = 0, mx = 0;
            for (int i = idx; i < min(idx + k, n); i++) {
                mx = max(mx, arr[i]);
                ans = max(ans, mx * (i - idx + 1) + self(self, i + 1));
            }
            return dp[idx] = ans;
        };
        return rec(rec, 0);
    }
};