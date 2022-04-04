#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 6 ms faster than: 10.98%
   Memory Usage: 6 MB less than: 45.04%
   Remarks:
*/

class Solution {
   public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = abs(n);
        }
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x * x, n / 2);
        }
    }
};