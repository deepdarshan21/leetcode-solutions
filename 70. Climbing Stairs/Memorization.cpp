#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization (DP)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 21.33%
   Memory Usage: 6.2 MB less than: 30.42%
   Remarks:
*/

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return help(0, n, dp);
    }
    int help(int curr, int &n, vector<int> &dp) {
        if (curr == n) return 1;
        if (dp[curr] != -1) return dp[curr];
        if ((curr + 2) <= n)
            dp[curr] = help(curr + 1, n, dp) + help(curr + 2, n, dp);
        else
            dp[curr] = help(curr + 1, n, dp);
        return dp[curr];
    }
};