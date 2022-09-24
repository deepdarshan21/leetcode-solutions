#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
        Do a right shift to create blank space a leftmost digit and then add the numbers leftmost digit
        then do left shift in num to remove that digit;

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 5.60%
   Memory Usage: 5.9 MB less than: 51.60%
   Remarks:
*/

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = res << 1;
            res += n % 2;
            n = n >> 1;
        }
        return res;
    }
};