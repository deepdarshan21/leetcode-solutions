#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP


   Edge Cases:

   Time Complexity: O(m^2) Space: O(m^2)
   Status: Accepted
   Runtime: 879 ms faster than: 27.51%
   Memory Usage: 120 MB less than: 68.36%
   Remarks:
*/

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // memset(memo, 2147483647, sizeof(memo));
        n = nums.size();
        m = multipliers.size();
        memo.resize(m, vector<int>(m, INT_MIN));
        return dp(nums, multipliers, 0, 0);
    }

   private:
    // int memo[1000][1000];
    vector<vector<int>> memo;
    int m, n;
    int dp(vector<int>& nums, vector<int>& multipliers, int l, int i) {
        if (i == m) return 0;
        if (memo[l][i] != INT_MIN) return memo[l][i];
        int r, left, right;
        r = n - 1 - (i - l);
        left = nums[l] * multipliers[i] + dp(nums, multipliers, l + 1, i + 1);
        right = nums[r] * multipliers[i] + dp(nums, multipliers, l, i + 1);
        memo[l][i] = max(left, right);
        return memo[l][i];
    }
};