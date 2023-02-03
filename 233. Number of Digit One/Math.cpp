#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 42.36%
   Memory Usage: 6 MB less than: 75%
   Remarks:
*/

class Solution {
   public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            res += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return res;
    }
};