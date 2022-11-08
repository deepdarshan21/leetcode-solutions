#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dynamic Programming (Bottom Up)
        dp[i][j] will store longest common subarray of nums1[i:] or nums2[j:]

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 322 ms faster than: 85.10%
   Memory Usage: 85.5 MB less than: 54.68%
   Remarks:
*/

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(m, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};