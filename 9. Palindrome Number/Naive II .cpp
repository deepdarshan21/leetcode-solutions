#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Reverse Number
        In this approch, first reverse the number and while reversing check for overflow,
        if there is overflow means number is not palindrome(as it can't be store in INT again)

   Edge Cases:
        1. If number is negative
        2. Overflow in positive number

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 96.54%
   Memory Usage: 5.9 MB less than: 31.60%
*/

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int num, revNum, temp;
        num = x;
        revNum = 0;
        while (x > 0) {
            temp = x % 10;
            x = x / 10;
            if (revNum > INT32_MAX / 10 || (revNum == INT32_MAX / 10 && temp > 7)) {
                return false;
            }
            revNum = revNum * 10 + temp;
        }
        if (num == revNum) {
            return true;
        }
        return false;
    }
};