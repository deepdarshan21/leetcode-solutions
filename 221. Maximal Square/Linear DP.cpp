#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear DP

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 83 ms faster than: 93.71%
   Memory Usage: 18.6 MB less than: 95.95%
   Remarks:
*/

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int dia = 0;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if (matrix[i][j - 1] == '0')
                    dp[j] = 0;
                else {
                    dp[j] = min({dp[j - 1], dia, dp[j]}) + 1;
                    res = max(res, dp[j]);
                }
                dia = tmp;
            }
        }
        return res * res;
    }
};