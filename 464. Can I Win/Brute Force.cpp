#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        int temp = 0;
        while (desiredTotal > 0 && maxChoosableInteger > temp) {
            if (maxChoosableInteger >= desiredTotal) return true;
            if ((2 * maxChoosableInteger - 1) < desiredTotal) {
                desiredTotal -= maxChoosableInteger;
                maxChoosableInteger--;
            } else {
                temp++;
                desiredTotal -= temp;
            }
            if (maxChoosableInteger >= desiredTotal) return false;
            if ((2 * maxChoosableInteger - 1) < desiredTotal) {
                desiredTotal -= maxChoosableInteger;
                maxChoosableInteger--;
            } else {
                temp++;
                desiredTotal -= temp;
            }
            temp++;
            desiredTotal -= temp;
        }
        return false;
    }
};