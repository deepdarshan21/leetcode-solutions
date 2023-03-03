#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtracking

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        auto rec = [&](auto &&self, int idx) -> int {
            if (idx >= n) return 1;
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
            return res % mod;
        };
        return rec(rec, 0);
    }
};