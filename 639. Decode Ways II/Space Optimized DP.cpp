#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 578 ms faster than: 5.22%
   Memory Usage: 11.8 MB less than: 92.77%
   Remarks:
*/

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        int curr, prev, prev2;

        prev2 = 1;
        prev = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            if (s[idx] == '0') {
                curr = 0;
                prev2 = prev;
                prev = curr;
                continue;
            }

            int res = 0;
            if (s[idx] != '*') {
                res = (res + prev % mod) % mod;
                if (idx + 1 < n) {
                    if (s[idx + 1] != '*') {
                        string tmp = "";
                        tmp += s[idx];
                        tmp += s[idx + 1];
                        if (stoi(tmp) <= 26)
                            res = (res + prev2 % mod) % mod;
                    } else {
                        for (int j = 1; j < 10; j++) {
                            string tmp = "";
                            tmp += s[idx];
                            if (stoi(tmp) * 10 + j <= 26)
                                res = (res + prev2 % mod) % mod;
                        }
                    }
                }
            } else {
                for (int i = 1; i < 10; i++) {
                    res = (res + prev % mod) % mod;
                    if (idx + 1 < n) {
                        if (s[idx + 1] != '*') {
                            string tmp = "";
                            tmp += to_string(i) + s[idx + 1];
                            if (stoi(tmp) <= 26)
                                res = (res + prev2 % mod) % mod;
                        } else {
                            for (int j = 1; j < 10; j++) {
                                if (i * 10 + j <= 26)
                                    res = (res + prev2 % mod) % mod;
                            }
                        }
                    }
                }
            }
            curr = res % mod;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};