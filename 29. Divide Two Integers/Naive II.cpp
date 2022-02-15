#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:


   Time Complexity: O() Space: O()
   Status: Runntime Error(Overflow Condition)
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (divisor == -1 && dividend == INT_MIN) {
            return INT_MAX;
        }
        bool isNegative = false;
        if ((dividend < 0) ^ (divisor < 0)) {
            isNegative = true;
        }
        int sum = 0, quotient = 0;
        dividend = -abs(dividend);
        divisor = -abs(divisor);
        if (dividend < (INT_MIN - divisor)) {
            quotient++;
            dividend -= divisor;
        }
        while (sum + divisor >= dividend) {
            int tempSum = sum + divisor, tempCount = 1;
            while ((tempSum * 2) >= dividend) {
                tempSum += tempSum;
                tempCount++;
            }
            sum = tempSum;
            quotient += tempCount;
        }
        if (isNegative) {
            quotient *= -1;
        }
        return quotient;
    }
};