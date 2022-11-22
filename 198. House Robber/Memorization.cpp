#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.9 MB less than: 25%
   Remarks:
*/

class Solution {
   public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(help(n - 1, nums, dp), help(n - 2, nums, dp));
    }
    int help(int i, vector<int> &nums, vector<int> &dp) {
        if (i < 0) return 0;
        if (i <= 1) return nums[i];
        if (dp[i] != -1) return dp[i];
        dp[i] = nums[i] + max(help(i - 2, nums, dp), help(i - 3, nums, dp));
        return dp[i];
    }
};