#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dynamic Programming
        Store the possible number of arthimetic subarray can be created till that index in "dp" vector.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 49.49%
   Memory Usage: 7.4 MB less than: 16.43%
   Remarks:
*/

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 3) {
            return count;
        }
        vector<int> dp(nums.size());
        dp[0] = 0;
        dp[1] = 0;
        int first, second;
        for (int i = 2; i < nums.size(); i++) {
            first = nums[i] - nums[i - 1];
            second = nums[i - 1] - nums[i - 2];
            if (first == second) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 0;
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            count += dp[i];
        }
        return count;
    }
};