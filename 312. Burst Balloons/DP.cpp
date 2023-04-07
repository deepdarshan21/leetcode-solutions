#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n*n)
   Status: Accepted
   Runtime: 1078 ms faster than: 5.6%
   Memory Usage: 10.5 MB less than: 26.43%
   Remarks:
*/

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> rec = [&](int start, int end) -> int {
            if (end < start) return 0;
            if (dp[start][end] != -1) return dp[start][end];
            int res = 0;
            int prev, curr, next;
            for (int i = start; i <= end; i++) {
                prev = start == 0 ? 1 : nums[start - 1];
                curr = nums[i];
                next = end == n - 1 ? 1 : nums[end + 1];
                res = max(res, prev * curr * next + rec(start, i - 1) + rec(i + 1, end));
            }
            return dp[start][end] = res;
        };
        return rec(0, n - 1);
    }
};