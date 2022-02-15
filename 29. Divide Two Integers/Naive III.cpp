#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Subtract "divisor" from "dividend" until "dividend" not become smaller than equal
        to "divisor".

   Edge Cases:
        1. If "divisor" is -1 and "dividend" is INT_MIN -> return INT_MAX(can't store abs(INT_MIN) in "int")

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Make "divisor", "dividend" and "quotient" negative and make them positive again(if required)
*/

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isNegative = false;
        if ((dividend < 0) ^ (divisor < 0)) {
            isNegative = true;
        }
        int quotient = 0;
        dividend = -abs(dividend);
        divisor = -abs(divisor);
        while (dividend <= divisor) {
            int temp = divisor, tempQuotient = -1;
            while (dividend - temp <= temp) {
                temp += temp;
                tempQuotient += tempQuotient;
            }
            dividend -= temp;
            quotient += tempQuotient;
        }
        if (!isNegative) {
            return -quotient;
        }
        return quotient;
    }
};