#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Math
        First remove spaces from start of string, then check for "-" or "+" sign,
        then evaluate the number while checking for overflow in every step

   Edge Cases:


   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 75.86%
   Memory Usage: 7.1 MB less than: 13.45%
*/

class Solution {
   public:
    int myAtoi(string s) {
        bool isNegative = false;
        int num = 0, start = 0, temp;
        while (s[start] == ' ') {
            start++;
        }
        if (s[start] == '-') {
            isNegative = true;
            start++;
        } else if (s[start] == '+') {
            isNegative = false;
            start++;
        }
        while (s[start] >= '0' && s[start] <= '9') {
            temp = s[start] - '0';
            start++;
            if (isNegative) {
                temp *= -1;
                if (num < INT32_MIN / 10 || (num == INT32_MIN / 10 && temp < -8)) {
                    return INT32_MIN;
                } else {
                    num = num * 10 + temp;
                }
            } else {
                if (num > INT32_MAX / 10 || (num == INT32_MAX / 10 && temp > 7)) {
                    return INT32_MAX;
                } else {
                    num = num * 10 + temp;
                }
            }
        }
        return num;
    }
};