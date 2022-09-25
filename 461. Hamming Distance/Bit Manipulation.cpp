#include <bits/stdc++.h>
using namespace std;

/*
   Approach: XOR and count no. of 1's

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 6 ms faster than: 9.59%
   Memory Usage: 5.9 MB less than: 27.45%
   Remarks:
*/

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};