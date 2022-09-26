#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Traverse every digit and verify the condition

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 26.20%
   Remarks:
*/

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        bool zero, one;
        if ((n & 1) == 1) {
            one = true;
            zero = false;
        } else {
            zero = true;
            one = false;
        }
        n = n >> 1;
        while (n != 0) {
            int temp = n & 1;
            if (zero && temp == 1) {
                zero = false;
                one = true;
            } else if (one && temp == 0) {
                one = false;
                zero = true;
            } else {
                return false;
            }
            n = n >> 1;
        }
        return true;
    }
};