#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n*n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 58.9%
   Memory Usage: 5.9 MB less than: 93.14%
   Remarks:
*/

class Solution {
   public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};