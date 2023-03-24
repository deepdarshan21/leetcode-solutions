#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n*n)
   Status: Accepted
   Runtime: 124 ms faster than: 5.9%
   Memory Usage: 15.6 MB less than: 6.1%
   Remarks:
*/

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        function<int(int, int)> rec = [&](int idx1, int idx2) {
            if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
            if (idx1 == n1) {
                int tmp = 0;
                for (int i = idx2; i < n2; i++) tmp += s2[i];
                return dp[idx1][idx2] = tmp;
            }
            if (idx2 == n2) {
                int tmp = 0;
                for (int i = idx1; i < n1; i++) tmp += s1[i];
                return dp[idx1][idx2] = tmp;
            }
            if (s1[idx1] == s2[idx2]) return dp[idx1][idx2] = rec(idx1 + 1, idx2 + 1);
            int res1, res2;
            // delete s1's char
            res1 = s1[idx1] + rec(idx1 + 1, idx2);
            // delete s2's char
            res2 = s2[idx2] + rec(idx1, idx2 + 1);
            return dp[idx1][idx2] = min(res1, res2);
        };

        return rec(0, 0);
    }
};