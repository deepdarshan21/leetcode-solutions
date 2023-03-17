#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP (top down)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(nlogn)
   Status: Accepted
   Runtime: 618 ms faster than: 7.69%
   Memory Usage: 53.9 MB less than: 5.26%
   Remarks:
*/

class Solution {
   public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        auto rec = [&](auto self, int n, int turn) -> bool {
            if (n == 0) return turn == 1;
            if (dp[n][turn] != -1) return dp[n][turn];
            for (int i = 1; i * i <= n; i++) {
                if (turn == 0)
                    if (self(self, n - i * i, 1 - turn)) return dp[n][turn] = true;
                if (turn == 1)
                    if (!self(self, n - i * i, 1 - turn)) return dp[n][turn] = false;
            }
            return dp[n][turn] = turn != 0;
        };
        return rec(rec, n, 0);
    }
};