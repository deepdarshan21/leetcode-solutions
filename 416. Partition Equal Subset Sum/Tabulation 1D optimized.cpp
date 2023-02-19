#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation 1D optimized
        We can use the same approach as the previous problem.
        But we can optimize the space complexity by using only one row of the table.
        We can do this by using the same row to store the previous row's values.
        We can do this by starting from the end of the row and going backwards.
        This is because we are using the previous row's values to calculate the current row's values.
        So if we start from the end, we will not overwrite the previous row's values.

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n)
   Status: Accepted
   Runtime: 328 ms faster than: 54.94%
   Memory Usage: 9.8 MB less than: 90.7%
   Remarks:
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        if (nums[0] <= target) dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = target; j >= 0; j--) {
                bool nt = dp[j];
                bool t = false;
                if (j >= nums[i]) t = dp[j - nums[i]];
                dp[j] = nt || t;
            }
        }
        return dp[target];
    }
};