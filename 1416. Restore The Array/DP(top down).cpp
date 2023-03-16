#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 302 ms faster than: 17.37%
   Memory Usage: 54.3 MB less than: 6.59%
   Remarks:
*/

class Solution {
   public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> dp(n, -1);

        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 1;
            if (dp[idx] != -1) return dp[idx];
            if (s[idx] == '0') return dp[idx] = 0;
            string num = "";
            int res = 0;
            for (int i = idx; i < n; i++) {
                num += s[i];
                if (stoll(num) > k) break;
                res = (res + self(self, i + 1)) % mod;
            }
            return dp[idx] = res;
        };

        return rec(rec, 0);
    }
};