#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.9 MB less than: 17.23%
   Remarks:
*/

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0, tmp;
        for (int i = n - 1; i >= 0; i--) {
            tmp = digits[i] + carry + 1;
            if (i == n - 1) tmp++;
            if (tmp < 10) {
                digits[i] = tmp;
                carry = 0;
                break;
            }
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};