#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math Combination

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 2 ms faster than: 98.18%
   Memory Usage: 5.9 MB less than: 99.45%
   Remarks:
*/

class Solution {
   public:
    int numberOfWays(int startPos, int endPos, int k) {
        int mod = 1e9 + 7;
        auto inv = [&](auto inv, long long a) {
            if (a == 1) return 1LL;
            return (mod - mod / a) * inv(inv, mod / a) % mod;
        };
        int diff = abs(endPos - startPos);
        if (diff > k || (k - diff) % 2) return 0;
        int pos = 0, neg = 0;
        if (startPos < endPos) {
            neg = (k - diff) / 2;
            pos = diff + neg;
        } else {
            pos = (k - diff) / 2;
            neg = diff + pos;
        }
        int n = min(pos, neg);
        long long res = 1LL;
        for (int i = 0; i < n; i++) {
            res = res * (k - i) % mod;
            res = res * inv(inv, i + 1) % mod;
        }
        return (int)res;
    }
};