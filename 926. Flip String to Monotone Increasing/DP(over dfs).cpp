#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(over previous dfs)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 394 ms faster than: 5.6%
   Memory Usage: 125.9 MB less than: 5.6%
   Remarks:
*/

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        auto dfs = [&](auto dfs, char last, int i) {
            if (i == n) return 0;
            if (dp[i][last - 48] != -1) return dp[i][last - 48];
            int res = INT_MAX;
            if (last == '1') {
                res = dfs(dfs, '1', i + 1);
            } else {
                res = min(res, dfs(dfs, '0', i + 1));
                res = min(res, dfs(dfs, '1', i + 1));
            }
            if (s[i] != last) res++;
            return dp[i][last - 48] = res;
        };
        return min(dfs(dfs, '0', 0), dfs(dfs, '1', 0));
    }
};