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
    int knightDialer(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> help = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4},
        };
        auto rec = [&](auto rec, int n, int prev) -> int {
            if (n == 0) return 1;
            int ans = 0;
            for (int i : help[prev]) {
                ans = (ans + rec(rec, n - 1, i)) % mod;
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + rec(rec, n - 1, i)) % mod;
        }
        return ans;
    }
};