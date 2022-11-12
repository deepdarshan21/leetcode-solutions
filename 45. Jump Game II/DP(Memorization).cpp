#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization on recursion

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 877 ms faster than: 19.27%
   Memory Usage: 18.4 MB less than: 6.40%
   Remarks:
*/

class Solution {
   public:
    int jump(vector<int> &nums) {
        vector<int> dp(nums.size(), 100001);
        return jump(nums, dp, 0);
    }
    int jump(vector<int> &nums, vector<int> &dp, int pos) {
        if (pos == nums.size() - 1) return 0;
        if (dp[pos] != 100001) return dp[pos];
        for (int i = 1; i < nums[i] && (pos + i) < nums.size(); i++) {
            dp[pos] = min(dp[pos], jump(nums, dp, pos + i));
        }
        return dp[pos];
    }
};