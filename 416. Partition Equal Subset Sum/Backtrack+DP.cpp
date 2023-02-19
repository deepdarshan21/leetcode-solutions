#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtrack + DP
        Just reduce the problem that we need to find a subset that sums up to half of the total sum.
        Then we can use the same approach as the previous problem.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 147 ms faster than: 87%
   Memory Usage: 95.2 MB less than: 23%
   Remarks:
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        auto rec = [&](auto rec, int i, int sum) -> bool {
            if (i == n && sum != 0) return false;
            if (i == n && sum == 0) return true;
            if (sum < 0) return false;
            if (dp[i][sum] != -1) return dp[i][sum] == 1;
            if (sum == 0) {
                dp[i][sum] = true;
                return true;
            }
            dp[i][sum] = rec(rec, i + 1, sum - nums[i]) || rec(rec, i + 1, sum);
            return dp[i][sum] == 1;
        };
        return rec(rec, 0, target);
    }
};