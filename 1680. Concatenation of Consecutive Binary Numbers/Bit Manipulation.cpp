#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit manipulation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 295 ms faster than: 35.87%
   Memory Usage: 6.1 MB less than: 22.83%
   Remarks:
*/

class Solution {
   public:
    int concatenatedBinary(int n) {
        int res = 0;
        int mod = 10e8 + 7;
        for (int i = 1; i <= n; i++) {
            int len = log2(i) + 1;
            res = long(res * pow(2, len) + i) % mod;
        }
        return res;
    }
};