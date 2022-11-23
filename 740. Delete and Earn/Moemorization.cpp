#include <bits/stdc++.h>
using namespace std;

/*
   Approach: memorization

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 36 ms faster than: 37%
   Memory Usage: 21.7 MB less than: 7.71%
   Remarks:
*/

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 20001;
        vector<int> mp(n, 0);
        for (int num : nums) mp[num]++;
        vector<int> dp(n + 1, -1);
        return max(help(mp, n - 1, dp), help(mp, n - 2, dp));
    }
    int help(vector<int>& mp, int n, vector<int>& dp) {
        if (n < 0) return 0;
        if (n < 2) return mp[n];
        if (dp[n] != -1) return dp[n];
        return dp[n] = n * mp[n] + max(help(mp, n - 2, dp), help(mp, n - 3, dp));
    }
};