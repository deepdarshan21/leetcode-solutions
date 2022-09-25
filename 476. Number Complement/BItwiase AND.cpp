#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bitwise AND

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status:  Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 11.50%
   Remarks:
*/

class Solution {
   public:
    int findComplement(int num) {
        unsigned temp = num;
        temp = ~temp;
        int t = log2(num) + 1;
        unsigned tmp = (unsigned)(pow(2, t)) - 1;
        temp = temp & tmp;
        return (int)temp;
    }
};