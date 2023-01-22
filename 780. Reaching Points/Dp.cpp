#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Runtime Error(Stack overflow)
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        unordered_map<int, unordered_map<int, int>> dp;
        auto help = [&](auto help, int x, int y) {
            if (x < sx || y < sy || x > tx || y > ty || dp[x][y] == 2) return false;
            if (x == tx && y == ty) return true;
            if (dp[x][y] == 1) return true;
            dp[x][y] = 2;
            if (help(help, x, x + y)) {
                dp[x][y] == 1;
                return true;
            }
            if (help(help, x + y, y)) {
                dp[x][y] == 1;
                return true;
            }
            return false;
        };
        return help(help, sx, sy);
    }
};