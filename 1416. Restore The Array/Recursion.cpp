#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7;

        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 1;
            if (s[idx] == '0') return 0;
            string num = "";
            int res = 0;
            for (int i = idx; i < n; i++) {
                num += s[i];
                if (stoi(num) > k) break;
                res = (res + self(self, i + 1)) % mod;
            }
            return res;
        };

        return rec(rec, 0);
    }
};