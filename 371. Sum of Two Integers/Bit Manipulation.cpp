#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int getSum(int a, int b) {
        while (b) {
            unsigned c = a & b;
            a ^= b;
            b = c << 1;
        }
        return a;
    }
};