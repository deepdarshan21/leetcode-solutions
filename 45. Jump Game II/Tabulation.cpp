#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 447 ms faster than: 37.46%
   Memory Usage: 17.2 MB less than: 27.90%
   Remarks:
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 100001);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && (i + j) < n; j++) {
                dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }
        return dp[0];
    }
};