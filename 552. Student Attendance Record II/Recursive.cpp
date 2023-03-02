#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursive
                Check all possible combinations of P, L, A

   Edge Cases:

   Time Complexity: O(3^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        auto rec = [&](auto &&self, int n, int allowedAbsent, int allowedLate) {
            if (n == 0) return 1;
            int res = 0;
            if (allowedAbsent > 0) res = (res + self(self, n - 1, allowedAbsent - 1, 2)) % mod;
            if (allowedLate > 0) res = (res + self(self, n - 1, allowedAbsent, allowedLate - 1)) % mod;
            res = (res + self(self, n - 1, allowedAbsent, allowedLate)) % mod;
            return res;
        };
        return rec(rec, n, 1, 2) % mod;
    }
};