#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 3 ms faster than: 45.99%
   Memory Usage: 6.7 MB less than: 8.02%
   Remarks:
*/

class Solution {
   public:
    string strWithout3a3b(int a, int b, char aa = 'a', char bb = 'b') {
        if (a < b) return strWithout3a3b(b, a, bb, aa);
        if (b == 0) return string(a, aa);
        int useA = a > b ? 2 : 1, useB = 1;
        return string(useA, aa) + string(useB, bb) + strWithout3a3b(a - useA, b - useB, aa, bb);
    }
};