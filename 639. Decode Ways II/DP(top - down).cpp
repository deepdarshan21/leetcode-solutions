#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)
        Use recursion to solve the problem and store the result in a vector
        to avoid repeated calculations.
        Try to solve the problem for the last character and then the second
        last character and so on.
        If the last character is not '*', then the number of ways to decode
        the string is equal to the number of ways to decode the string
        without the last character.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 644 ms faster than: 5.22%
   Memory Usage: 111.8 MB less than: 5.22%
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> dp(n, -1);
        auto rec = [&](auto &&self, int idx) -> int {
            if (idx >= n) return 1;
            if (dp[idx] != -1) return dp[idx];
            if (s[idx] == '0') return 0;
            int res = 0;
            if (s[idx] != '*') {
                res = (res + self(self, idx + 1) % mod) % mod;
                if (idx + 1 < n) {
                    if (s[idx + 1] != '*') {
                        string tmp = "";
                        tmp += s[idx];
                        tmp += s[idx + 1];
                        if (stoi(tmp) <= 26)
                            res = (res + self(self, idx + 2) % mod) % mod;
                    } else {
                        for (int j = 1; j < 10; j++) {
                            string tmp = "";
                            tmp += s[idx];
                            if (stoi(tmp) * 10 + j <= 26)
                                res = (res + self(self, idx + 2) % mod) % mod;
                        }
                    }
                }
            } else {
                for (int i = 1; i < 10; i++) {
                    res = (res + self(self, idx + 1) % mod) % mod;
                    if (idx + 1 < n) {
                        if (s[idx + 1] != '*') {
                            string tmp = "";
                            tmp += to_string(i) + s[idx + 1];
                            if (stoi(tmp) <= 26)
                                res = (res + self(self, idx + 2) % mod) % mod;
                        } else {
                            for (int j = 1; j < 10; j++) {
                                if (i * 10 + j <= 26)
                                    res = (res + self(self, idx + 2) % mod) % mod;
                            }
                        }
                    }
                }
            }
            return dp[idx] = res % mod;
        };
        return rec(rec, 0);
    }
};