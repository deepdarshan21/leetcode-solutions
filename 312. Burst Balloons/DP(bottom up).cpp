#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n*n)
   Status: Accepted
   Runtime: 352 ms faster than: 80.63%
   Memory Usage: 10.4 MB less than: 61.81%
   Remarks:
*/

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                if (start > end) continue;
                int res = 0;
                int prev, curr, next;
                for (int i = start; i <= end; i++) {
                    prev = nums[start - 1];
                    curr = nums[i];
                    next = nums[end + 1];
                    res = max(res, prev * curr * next + dp[start][i - 1] + dp[i + 1][end]);
                }
                dp[start][end] = res;
            }
        }
        return dp[1][n];
    }
};