#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:


   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (divisor == 1 && dividend == INT_MIN) {
            return INT_MIN;
        }
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
        // cout<<dividend<<abs(dividend)<<endl;
        while (sum + divisor >= dividend) {
            sum += divisor;
            quotient++;
        }
        if (isNegative) {
            quotient *= -1;
        }
        return quotient;
    }
};