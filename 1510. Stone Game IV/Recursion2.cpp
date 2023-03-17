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
    bool winnerSquareGame(int n) {
        auto rec = [&](auto rec, int n) -> bool {
            if (n == 0) return false;
            for (int i = 1; i * i <= n; i++) {
                if (!rec(rec, n - i * i)) return true;
            }
            return false;
        };
        return rec(rec, n);
    }
};