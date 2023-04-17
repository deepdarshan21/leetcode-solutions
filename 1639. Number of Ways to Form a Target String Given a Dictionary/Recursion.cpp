#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        check for every possible condition

   Edge Cases:

   Time Complexity: O(m*n^(m*len)) Space: O(m*len)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = words[0].size(), len = target.size();
        int mod = 1e9 + 7;

        auto help = [&](auto self, int k, int i) {
            if (i >= len) return 1;
            if (k >= n) return 0;
            int res = 0;
            for (int j = 0; j < n; j++) {
                for (int idx = k; idx < m; idx++) {
                    if (target[i] == words[j][idx]) {
                        res = (res + self(self, idx + 1, i + 1)) % mod;
                    }
                }
            }
            return res;
        };

        return help(help, 0, 0);
    }
};