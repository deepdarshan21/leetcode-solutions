#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        f(1) = 1
        f(2) = 2
        f(3) = 5 (|||, |-, -|, L, ulta L)
        f(4) = 11 (|f(3), ||f(2), -f(2), L-ultaL, ultaL-L)

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        auto rec = [&](auto&& rec, int n) -> int {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;
            if (n == 3) return 5;
            int res = 0;
            res = (res + 2 * rec(rec, n - 1)) % mod;
            res = (res + rec(rec, n - 3)) % mod;
            return res;
        };
        return rec(rec, n);
    }
};