#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math
        Total odd number between to two numbers is half the difference between both numbers

   Edge Cases:
        1. If the corner number is odd => add one to count

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 25.92%
   Remarks:
*/

class Solution {
   public:
    int countOdds(int low, int high) {
        int oddCount = (high - low) / 2;
        if (low % 2 == 1 || high % 2 == 1) {
            oddCount++;
        }
        return oddCount;
    }
};