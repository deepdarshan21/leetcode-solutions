#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy(Math)

   Edge Cases:

   Time Complexity: O(digit_length^2) Space: O(digit_length)
   Status: Accepeted
   Runtime: 2 ms faster than: 47.71%
   Memory Usage: 5.9 MB less than: 86.06%
   Remarks:
*/

class Solution {
   public:
    int maximumSwap(int num) {
        vector<int> digits;
        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int i = 0, maxI = -1, n = digits.size();
        while (i < n) {
            if (i > maxI)
                maxI = max_element(digits.begin() + maxI + 1, digits.end(), [](int a, int b) {
                           return a <= b;
                       }) -
                       digits.begin();
            if (digits[i] < digits[maxI]) {
                swap(digits[i], digits[maxI]);
                break;
            }
            i++;
        }
        int res = 0;
        for (int digit : digits) res = res * 10 + digit;
        return res;
    }
};