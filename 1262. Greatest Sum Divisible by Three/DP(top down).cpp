#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)
        Start from the first element and try to include it in the sum and
        exclude it from the sum. If the sum is divisible by 3, then update
        the result.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 141 ms faster than: 6.85%
   Memory Usage: 58 MB less than: 5.82%
   Remarks:
*/

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        auto rec = [&](auto self, int idx, int rem) -> int {
            if (idx == n) return rem ? INT_MIN : 0;
            if (dp[idx][rem] != -1) return dp[idx][rem];
            int tmp1, tmp2;
            tmp1 = self(self, idx + 1, rem);
            tmp2 = nums[idx] + self(self, idx + 1, (rem + nums[idx]) % 3);
            return dp[idx][rem] = max(tmp1, tmp2);
        };
        return rec(rec, 0, 0);
    }
};