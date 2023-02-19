#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation
        We can use the same approach as the previous problem.
        We can use a 2D array to store the results of the subproblems.
        dp[i][j] means whether we can find a subset that sums up to j using the first i elements.
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 513 ms faster than: 21.18%
   Memory Usage: 13.2 MB less than: 66.25%
   Remarks: We can reduce the space complexity to O(target) by using a 1D array.
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target) dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool nt = dp[i - 1][j];
                bool t = false;
                if (j >= nums[i]) t = dp[i - 1][j - nums[i]];
                dp[i][j] = nt || t;
            }
        }
        return dp[n - 1][target];
    }
};