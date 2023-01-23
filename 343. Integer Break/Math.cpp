#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 27.18%
   Memory Usage: 6 MB less than: 82.86%
   Remarks:
*/

class Solution {
   public:
    int integerBreak(int n) {
        int res = 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        while (n > 0) {
            if (n - 3 < 2 && (n - 3) != 0) {
                n -= 2;
                res *= 2;
            } else {
                n -= 3;
                res *= 3;
            }
        }
        return res;
    }
};