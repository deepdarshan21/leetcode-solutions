#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Math
        Check for over flow condition before adding

   Edge Cases:


   Time Complexity: O(log(n)) Space: O(1)
   Satus: Accepted
   Runtime: 4 ms faster than: 44.11%
   Memory Usage : 6 MB less than: 31.68%
*/

class Solution {
   public:
    int reverse(int x) {
        int revInteger = 0, temp;
        while (x != 0) {
            temp = x % 10;
            x /= 10;

            if (revInteger > INT32_MAX / 10 || (revInteger == INT32_MAX / 10 && temp > 7)) {
                return 0;
            }
            if (revInteger < INT32_MIN / 10 || (revInteger == INT32_MIN / 10 && temp < -8)) {
                return 0;
            }

            revInteger = revInteger * 10 + temp;
        }
        return revInteger;
    }
};