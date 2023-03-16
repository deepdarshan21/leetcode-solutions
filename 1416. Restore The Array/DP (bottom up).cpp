#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 183 ms faster than: 20.96%
   Memory Usage: 11.9 MB less than: 81.44%
   Remarks:
*/

class Solution {
   public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> dp(n + 1, -1);

        dp[n] = 1;
        for (int idx = n - 1; idx >= 0; idx--) {
            if (s[idx] == '0')
                dp[idx] = 0;
            else {
                string num = "";
                int res = 0;
                for (int i = idx; i < n; i++) {
                    num += s[i];
                    if (stoll(num) > k) break;
                    res = (res + dp[i + 1]) % mod;
                }
                dp[idx] = res;
            }
        }

        return dp[0];
    }
};