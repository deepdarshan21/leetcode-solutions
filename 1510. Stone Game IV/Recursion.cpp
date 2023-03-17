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
        auto rec = [&](auto self, int n, int turn) -> bool {
            if (n == 0) return turn == 1;
            for (int i = 1; i * i <= n; i++) {
                if (turn == 0)
                    if (self(self, n - i * i, 1 - turn)) return true;
                if (turn == 1)
                    if (!self(self, n - i * i, 1 - turn)) return false;
            }
            return turn != 0;
        };
        return rec(rec, n, 0);
    }
};