#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(nk) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 83.55%
   Memory Usage: 8.6 MB less than: 75.77%
   Remarks:
*/

class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int ans = 0, mx = 0;
            for (int j = i; j < min(i + k, n); j++) {
                mx = max(mx, arr[j]);
                ans = max(ans, mx * (j - i + 1) + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};