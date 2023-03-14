#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Space Optimized DP

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 58 ms faster than: 70%
   Memory Usage: 25 MB less than: 60%
   Remarks:
*/

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3, INT_MIN), curr(3);

        dp[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                curr[j] = max(dp[j], nums[i] + dp[(j + nums[i]) % 3]);
            }
            swap(dp, curr);
        }
        return dp[0];
    }
};