#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        dp[i] = number of ways to decode s[0...i]
        dp[i] = dp[i - 1] + dp[i - 2] if s[i - 1] != '*' and s[i - 2] != '*'
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] if s[i - 1] == '*' and s[i - 2] == '*'
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] if s[i - 1] == '*' and s[i - 2] != '*'
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] if s[i - 1] != '*' and s[i - 2] == '*'
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] if s[i - 1] == '*' and s[i - 2] == '*' and s[i - 3] == '*' and s[i - 4] == '*' and s[i - 5] == '*'

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 1583 ms faster than: 5.22%
   Memory Usage: 16.9 MB less than: 85.14%
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> dp(n + 2, -1);

        dp[n + 1] = 1;
        dp[n] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            if (s[idx] == '0') {
                dp[idx] = 0;
                continue;
            }

            int res = 0;
            if (s[idx] != '*') {
                res = (res + dp[idx + 1] % mod) % mod;
                if (idx + 1 < n) {
                    if (s[idx + 1] != '*') {
                        string tmp = "";
                        tmp += s[idx];
                        tmp += s[idx + 1];
                        if (stoi(tmp) <= 26)
                            res = (res + dp[idx + 2] % mod) % mod;
                    } else {
                        for (int j = 1; j < 10; j++) {
                            string tmp = "";
                            tmp += s[idx];
                            if (stoi(tmp) * 10 + j <= 26)
                                res = (res + dp[idx + 2] % mod) % mod;
                        }
                    }
                }
            } else {
                for (int i = 1; i < 10; i++) {
                    res = (res + dp[idx + 1] % mod) % mod;
                    if (idx + 1 < n) {
                        if (s[idx + 1] != '*') {
                            string tmp = "";
                            tmp += to_string(i) + s[idx + 1];
                            if (stoi(tmp) <= 26)
                                res = (res + dp[idx + 2] % mod) % mod;
                        } else {
                            for (int j = 1; j < 10; j++) {
                                if (i * 10 + j <= 26)
                                    res = (res + dp[idx + 2] % mod) % mod;
                            }
                        }
                    }
                }
            }
            dp[idx] = res % mod;
        }
        return dp[0];
    }
};