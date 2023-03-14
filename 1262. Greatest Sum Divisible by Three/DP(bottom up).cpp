#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        dp[i][j] = max(dp[i + 1][j], nums[i] + dp[i + 1][(j + nums[i]) % 3])

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 107 ms faster than: 27.74%
   Memory Usage: 38.4 MB less than: 38.1%
   Remarks:
*/

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));

        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = max(dp[i + 1][j], nums[i] + dp[i + 1][(j + nums[i]) % 3]);
            }
        }
        return dp[0][0];
    }
};