#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
        "&"-> Binary AND operator
        if n-> xxx1000...
        then n-1 -> xxx0111...
        so, binary AND of n and n-1 (n & (n-1)) is xxx0000
        Repeating this thing will give total number of "1" in given binary number

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6 MB less than: 48.11%
   Remarks:
*/

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        while (n != 0) {
            n = n & (n - 1);
            total++;
        }
        return total;
    }
};